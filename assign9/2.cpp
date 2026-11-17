#include <stdio.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node *first = NULL, *middle = NULL, *last = NULL, *prev = NULL;

void inorder(struct Node *root) {
    if (root == NULL)
        return;

    inorder(root->left);

    if (prev != NULL && prev->data > root->data) {
        if (first == NULL) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }

    prev = root;

    inorder(root->right);
}

void recoverBST(struct Node *root) {
    inorder(root);

    struct Node *a = first;
    struct Node *b = (last != NULL) ? last : middle;

    if (a != NULL && b != NULL) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }
}

void printInorder(struct Node *root) {
    if (root == NULL)
        return;

    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    struct Node n1 = {6, NULL, NULL};
    struct Node n2 = {3, NULL, NULL};
    struct Node n3 = {8, NULL, NULL};
    struct Node n4 = {1, NULL, NULL};
    struct Node n5 = {7, NULL, NULL};
    struct Node n6 = {4, NULL, NULL};
    struct Node n7 = {9, NULL, NULL};

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    recoverBST(&n1);
    printInorder(&n1);

    return 0;
}