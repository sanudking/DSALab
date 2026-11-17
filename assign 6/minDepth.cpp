#include <iostream>
#include <algorithm>
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

class Solution {
public:
    int minDepth(Tree* root) {
        if (root == nullptr) {
            return 0;
        }
        
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

int main() {
    Tree* root = new Tree(3);
    root->left = new Tree(9);
    root->right = new Tree(20);
    root->right->left = new Tree(15);
    root->right->right = new Tree(7);

    Solution solver;
    cout << solver.minDepth(root) << endl; 

    return 0;
}
