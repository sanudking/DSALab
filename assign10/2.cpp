#include <iostream>
#include <vector>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    bool leftThread, rightThread;
    Node(int val) {
        data = val;
        left = right = NULL;
        leftThread = rightThread = false;
    }
};
Node* buildTree(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == -1)
        return NULL;
    vector<Node*> nodes(n, NULL);
    for (int i = 0; i < n; i++) {
        if (arr[i] != -1)
            nodes[i] = new Node(arr[i]);
    }
    for (int i = 0; i < n; i++) {
        if (nodes[i] == NULL)
            continue;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n)
            nodes[i]->left = nodes[left];
        if (right < n)
            nodes[i]->right = nodes[right];
    }
    return nodes[0];
}
void convertToThreaded(Node* root) {
    Node* curr = root;
    Node* prev = NULL;
    while (curr != NULL) {
        if (curr->left == NULL) {
            curr->left = prev;
            curr->leftThread = true;
            if (prev != NULL && prev->right == NULL) {
                prev->right = curr;
                prev->rightThread = true;
            }
            prev = curr;
            curr = curr->right;
        }
        else {
            Node* pred = curr->left;
            while (pred->right != NULL && pred->right != curr)
                pred = pred->right;
            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            }
            else {
                pred->rightThread = true;
                prev = curr;
                curr = curr->right;
            }
        }
    }
}
Node* leftmost(Node* root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL && !root->leftThread)
        root = root->left;
    return root;
}
void inorder(Node* root) {
    Node* curr = leftmost(root);
    while (curr != NULL) {
        cout << curr->data << " ";
        if (curr->rightThread)
            curr = curr->right;
        else
            curr = leftmost(curr->right);
    }
}
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter level-order elements (-1 for NULL): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node* root = buildTree(arr);
    convertToThreaded(root);
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}