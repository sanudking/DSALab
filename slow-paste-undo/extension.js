const vscode = require("vscode");

const pasteRecords = new Map();
const pendingPastes = new Map();
let activeAnimation;
let output;
let hiddenTextDecoration;

function documentKey(document) {
  return document.uri.toString();
}

function normalizeLineEndings(text) {
  return text.replace(/\r\n/g, "\n").replace(/\r/g, "\n");
}

function reportError(message, error) {
  output.appendLine(`${message}: ${error instanceof Error ? error.message : String(error)}`);
}

function clearAnimation(record) {
  record.cancelled = true;
  record.editor.setDecorations(hiddenTextDecoration, []);
  if (activeAnimation === record) {
    activeAnimation = undefined;
  }
}

function captureInsertion(event, pasteText) {
  const changes = event.contentChanges;
  if (changes.length !== 1 || changes[0].text.length === 0) {
    return undefined;
  }

  const change = changes[0];
  if (normalizeLineEndings(change.text) !== normalizeLineEndings(pasteText)) {
    return undefined;
  }

  return {
    document: event.document,
    startOffset: change.rangeOffset,
    text: change.text,
    version: event.document.version,
    running: false,
    cancelled: false
  };
}

async function tryCapturePaste(event, expectedText) {
  const record = captureInsertion(event, expectedText);
  if (record) {
    pasteRecords.set(documentKey(event.document), record);
  }
}

async function trackPaste(event) {
  const key = documentKey(event.document);
  const pending = pendingPastes.get(key);
  if (pending) {
    pendingPastes.delete(key);
    await tryCapturePaste(event, pending.text);
    return;
  }

  const candidate = event.contentChanges.length === 1 ? event.contentChanges[0] : undefined;
  if (!candidate || candidate.text.length === 0) {
    return;
  }

  try {
    const clipboardText = await vscode.env.clipboard.readText();
    if (event.document.version === candidate.version) {
      await tryCapturePaste(event, clipboardText);
    }
  } catch (error) {
    reportError("Unable to read clipboard to identify a paste", error);
  }
}

async function undo(editor) {
  if (!editor) {
    await vscode.commands.executeCommand("undo");
    return;
  }

  const key = documentKey(editor.document);
  const record = pasteRecords.get(key);
  if (!record || record.running || editor.document.version !== record.version) {
    await vscode.commands.executeCommand("undo");
    return;
  }

  const start = editor.document.positionAt(record.startOffset);
  const end = editor.document.positionAt(record.startOffset + record.text.length);
  const range = new vscode.Range(start, end);
  if (editor.document.getText(range) !== record.text) {
    pasteRecords.delete(key);
    await vscode.commands.executeCommand("undo");
    return;
  }

  record.running = true;
  record.editor = editor;
  activeAnimation = record;

  const delay = vscode.workspace.getConfiguration("slowPasteUndo").get("characterDelay", 35);
  const codePoints = Array.from(record.text);
  let hiddenLength = 0;

  try {
    for (let index = codePoints.length - 1; index >= 0; index -= 1) {
      await new Promise((resolve) => setTimeout(resolve, delay));
      if (record.cancelled || editor.document.version !== record.version ||
          vscode.window.activeTextEditor !== editor) {
        clearAnimation(record);
        return;
      }

      hiddenLength += codePoints[index].length;
      const suffixStart = editor.document.positionAt(
        record.startOffset + record.text.length - hiddenLength
      );
      const suffixEnd = editor.document.positionAt(record.startOffset + record.text.length);
      editor.setDecorations(hiddenTextDecoration, [
        new vscode.Range(suffixStart, suffixEnd)
      ]);
    }

    editor.setDecorations(hiddenTextDecoration, []);
    pasteRecords.delete(key);
    activeAnimation = undefined;
    await vscode.commands.executeCommand("undo");
  } catch (error) {
    reportError("Animated undo failed; using regular undo", error);
    editor.setDecorations(hiddenTextDecoration, []);
    pasteRecords.delete(key);
    activeAnimation = undefined;
    await vscode.commands.executeCommand("undo");
  }
}

async function paste(editor) {
  if (!editor) {
    await vscode.commands.executeCommand("editor.action.clipboardPasteAction");
    return;
  }

  const key = documentKey(editor.document);
  try {
    const text = await vscode.env.clipboard.readText();
    pendingPastes.set(key, { text });
  } catch (error) {
    reportError("Unable to read clipboard before paste", error);
  }

  await vscode.commands.executeCommand("editor.action.clipboardPasteAction");
  pendingPastes.delete(key);
}

function activate(context) {
  output = vscode.window.createOutputChannel("Slow Paste Undo");
  hiddenTextDecoration = vscode.window.createTextEditorDecorationType({
    color: "transparent"
  });

  context.subscriptions.push(
    output,
    hiddenTextDecoration,
    vscode.workspace.onDidChangeTextDocument((event) => {
      const key = documentKey(event.document);
      const record = pasteRecords.get(key);

      if (record?.running) {
        clearAnimation(record);
        pasteRecords.delete(key);
        return;
      }

      pasteRecords.delete(key);
      void trackPaste(event);
    }),
    vscode.window.onDidChangeActiveTextEditor((editor) => {
      if (activeAnimation && editor !== activeAnimation.editor) {
        clearAnimation(activeAnimation);
        pasteRecords.delete(documentKey(activeAnimation.document));
      }
    }),
    vscode.commands.registerCommand("slowPasteUndo.undo", () => undo(vscode.window.activeTextEditor)),
    vscode.commands.registerCommand("slowPasteUndo.paste", () => paste(vscode.window.activeTextEditor))
  );
}

function deactivate() {
  if (activeAnimation) {
    clearAnimation(activeAnimation);
  }
}

module.exports = {
  activate,
  deactivate
};
