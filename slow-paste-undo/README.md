# Slow Paste Undo

This VS Code extension makes `Cmd+Z` on macOS (or `Ctrl+Z` on Windows/Linux)
visually erase the most recent single-cursor paste from right to left, one
character at a time. When the animation finishes, VS Code's native undo removes
the paste, so the normal undo history is preserved.

Undo behaves normally when the most recent edit was not a paste. Paste through
the editor with `Cmd+V` / `Ctrl+V` or the editor's paste action. Changes made
after a paste invalidate it as the animated undo target.

The animation delay is configurable with `slowPasteUndo.characterDelay`
(milliseconds per character; default `35`).

## Run from source

1. Open this `slow-paste-undo` folder in VS Code.
2. Press `F5` to start an Extension Development Host.
3. In the new window, paste text into an editable file and press `Cmd+Z` or
   `Ctrl+Z`.

The extension has no external dependencies.
