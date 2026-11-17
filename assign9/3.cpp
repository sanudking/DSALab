#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int x) {
    struct Node* n = new Node;
    n->data = x;
    n->left = n->right = NULL;
    return n;
}
struct Node* insert(struct Node* root, int x) {
    if (root == NULL)
        return createNode(x);
    if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}
void initPredecessor(struct Node* root, int x, struct Node* stack[], int *top) {
    while (root != NULL) {
        if (root->data <= x) {
            stack[++(*top)] = root;
            root = root->right;
        } else {
            root = root->left;
        }
    }
}
void initSuccessor(struct Node* root, int x, struct Node* stack[], int *top) {
    while (root != NULL) {
        if (root->data > x) {
            stack[++(*top)] = root;
            root = root->left;
        } else {
            root = root->right;
        }
    }
}
int getPredecessor(struct Node* stack[], int *top) {
    struct Node* node = stack[(*top)--];
    int value = node->data;
    node = node->left;
    while (node != NULL) {
        stack[++(*top)] = node;
        node = node->right;
    }
    return value;
}
int getSuccessor(struct Node* stack[], int *top) {
    struct Node* node = stack[(*top)--];
    int value = node->data;
    node = node->right;
    while (node != NULL) {
        stack[++(*top)] = node;
        node = node->left;
    }
    return value;
}
void kClosest(struct Node* root, int x, int k) {
    struct Node* pred[1000];
    struct Node* succ[1000];
    int ptop = -1, stop = -1;
    initPredecessor(root, x, pred, &ptop);
    initSuccessor(root, x, succ, &stop);
    while (k-- > 0 && (ptop >= 0 || stop >= 0)) {
        if (ptop < 0) {
            printf("%d ", getSuccessor(succ, &stop));
        } else if (stop < 0) {
            printf("%d ", getPredecessor(pred, &ptop));
        } else {
            int p = pred[ptop]->data;
            int s = succ[stop]->data;
            if (abs(x - p) <= abs(s - x))
                printf("%d ", getPredecessor(pred, &ptop));
            else
                printf("%d ", getSuccessor(succ, &stop));
        }
    }
}
int main() {
    struct Node* root = NULL;
    int values[] = {10, 5, 15, 2, 7, 12, 20, 6, 8};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);
    int target = 9, k = 4;
    kClosest(root, target, k);
    return 0;
}