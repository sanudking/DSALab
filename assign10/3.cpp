#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(vector<int>& arr) {
    int n = arr.size();
    if (n == 0 || arr[0] == -1)
        return NULL;
    vector<Node*> nodes(n, NULL);
    for (int i = 0; i < n; i++)
        if (arr[i] != -1)
            nodes[i] = new Node(arr[i]);
    for (int i = 0; i < n; i++) {
        if (nodes[i] == NULL)
            continue;
        if (2 * i + 1 < n)
            nodes[i]->left = nodes[2 * i + 1];
        if (2 * i + 2 < n)
            nodes[i]->right = nodes[2 * i + 2];
    }
    return nodes[0];
}
void findParent(Node* root, unordered_map<Node*, Node*>& parent, Node*& target, int s) {
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr->data == s)
            target = curr;
        if (curr->left) {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right) {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
void distanceK(Node* root, int s, int k) {
    unordered_map<Node*, Node*> parent;
    Node* target = NULL;
    findParent(root, parent, target, s);
    queue<Node*> q;
    unordered_set<Node*> visited;
    q.push(target);
    visited.insert(target);
    int dist = 0;
    while (!q.empty()) {
        int size = q.size();
        if (dist == k) {
            while (!q.empty()) {
                cout << q.front()->data << " ";
                q.pop();
            }
            return;
        }
        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            if (curr->left && !visited.count(curr->left)) {
                visited.insert(curr->left);
                q.push(curr->left);
            }
            if (curr->right && !visited.count(curr->right)) {
                visited.insert(curr->right);
                q.push(curr->right);
            }
            if (parent.count(curr) && !visited.count(parent[curr])) {
                visited.insert(parent[curr]);
                q.push(parent[curr]);
            }
        }
        dist++;
    }
}
int main() {
    int n, s, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> s >> k;
    Node* root = buildTree(arr);
    distanceK(root, s, k);
    return 0;
}