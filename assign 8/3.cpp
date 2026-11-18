#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> kthSmallestAndLargestInBST(TreeNode* root, int k) {
        vector<int> ans;
        inorder(root, ans);

        int n = ans.size();
        return {ans[k - 1], ans[n - k]};
    }
};

int main() {
    Solution sol;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    vector<int> result =
        sol.kthSmallestAndLargestInBST(root, 3);

    cout << "Kth smallest: " << result[0]
         << ", Kth largest: " << result[1] << endl;
}