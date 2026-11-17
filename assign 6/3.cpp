#include <iostream>
#include <vector>
using namespace std;

struct Tree {
    int val;
    Tree* left;
    Tree* right;
    
    Tree(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(Tree* root, vector<int>& elements) {
    if (root == nullptr) return;
    inorder(root->left, elements);
    elements.push_back(root->val);
    inorder(root->right, elements);
}

int main() {
    Tree* root = new Tree(5);
    root->left = new Tree(3);
    root->right = new Tree(7);
    root->left->left = new Tree(2);
    root->left->right = new Tree(4);
    root->right->left = new Tree(6);
    root->right->right = new Tree(8);

    int k = 2;

    vector<int> elements;
    inorder(root, elements);
    
    int n = elements.size();
    int kthSmallest = elements[k - 1];
    int kthLargest = elements[n - k];
    
    cout << kthSmallest << " " << kthLargest << endl;

    return 0;
}
