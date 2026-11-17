#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

struct Info {
    bool isBST;
    long long sum;
    long long minValue;
    long long maxValue;
};

long long maxSum = LLONG_MIN;

Info solve(Node* root) {
    if (root == nullptr)
        return {true, 0, LLONG_MAX, LLONG_MIN};

    Info l = solve(root->left);
    Info r = solve(root->right);

    if (l.isBST && r.isBST &&
        l.maxValue < root->data &&
        root->data < r.minValue) {

        long long sum = l.sum + root->data + r.sum;
        maxSum = max(maxSum, sum);

        return {
            true,
            sum,
            min(l.minValue, (long long)root->data),
            max(r.maxValue, (long long)root->data)
        };
    }

    return {false, 0, LLONG_MIN, LLONG_MAX};
}

int main() {
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    solve(root);

    cout << "Maximum BST subtree sum = " << maxSum << endl;

    return 0;
}