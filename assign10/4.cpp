#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void inorder(Node* root, vector<int>& arr) {
    if (root == NULL)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}
int main() {
    int n, x;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    vector<int> arr;
    inorder(root, arr);
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        if (k <= 0 || k > arr.size())
            cout << -1 << " ";
        else
            cout << arr[k - 1] << " ";
    }
    return 0;
}