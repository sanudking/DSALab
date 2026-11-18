#include <iostream>
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

struct Tree {
    int node;
    Tree* left;
    Tree* right;

    Tree(int n) {
        node = n;
        left = nullptr;
        right = nullptr;
    }
};

void top(Tree* head) {
    if (head == nullptr) return;

    queue<pair<Tree*, int>> q;
    map<int, int> seen;

    q.push({head, 0});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Tree* curr = p.first;
        int hd = p.second;

        if (seen.find(hd) == seen.end()) {
            seen[hd] = curr->node;
        }

        if (curr->left != nullptr)
            q.push({curr->left, hd - 1});

        if (curr->right != nullptr)
            q.push({curr->right, hd + 1});
    }

    for (auto p : seen) {
        cout << p.second << " ";
    }
}

int main() {
    Tree* t1 = new Tree(10);
    Tree* t2 = new Tree(20);
    Tree* t3 = new Tree(30);
    Tree* t4 = new Tree(40);
    Tree* t5 = new Tree(50);
    Tree* t6 = new Tree(60);
    Tree* t7 = new Tree(70);

    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t2->right = t5;
    t3->left = t6;
    t3->right = t7;

    top(t1);

    return 0;
}