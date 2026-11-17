#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int data) : val(data), left(NULL), right(NULL) {}
};

class Solution {
public:
    void insert(TreeNode*& root, int x) {
        if (root->val > x) {
            if (root->left)
                insert(root->left, x);
            else
                root->left = new TreeNode(x);
        } else {
            if (root->right)
                insert(root->right, x);
            else
                root->right = new TreeNode(x);
        }
    }

    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root) return;

        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }

    vector<int> sortUsingBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return {};

        TreeNode* root = new TreeNode(nums[0]);

        for (int i = 1; i < n; i++)
            insert(root, nums[i]);

        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 3, 7, 2, 4, 6, 8};

    vector<int> sortedNums = sol.sortUsingBST(nums);

    for (int num : sortedNums)
        cout << num << " ";

    cout << endl;
}