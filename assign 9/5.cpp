#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void serialize(struct Node* root, FILE *fp) {
    if (root == NULL) {
        fprintf(fp, "# ");
        return;
    }

    fprintf(fp, "%d ", root->data);

    serialize(root->left, fp);
    serialize(root->right, fp);
}

struct Node* deserialize(FILE *fp) {
    char value[20];

    if (fscanf(fp, "%19s", value) != 1)
        return NULL;

    if (value[0] == '#')
        return NULL;

    int data = atoi(value);

    struct Node* root = createNode(data);

    root->left = deserialize(fp);
    root->right = deserialize(fp);

    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    FILE *fp = tmpfile();

    if (fp == NULL)
        return 1;

    printf("Original Tree (Inorder): ");
    inorder(root);

    rewind(fp);
    serialize(root, fp);

    printf("\nSerialized Tree: ");
    rewind(fp);

    char ch;
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);

    rewind(fp);

    struct Node* newRoot = deserialize(fp);

    printf("\nDeserialized Tree (Inorder): ");
    inorder(newRoot);

    printf("\n");

    fclose(fp);

    return 0;
}