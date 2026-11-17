#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* root) {
        return !root->left && !root->right;
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (isLeaf(root)) return 1;

        int leftDepth = 1e9, rightDepth = 1e9;

        if (root->left) leftDepth = minDepth(root->left);
        if (root->right) rightDepth = minDepth(root->right);

        return 1 + min(leftDepth, rightDepth);
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);

    cout << sol.minDepth(root) << endl;
}