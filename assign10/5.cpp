#include <iostream>
#include <vector>
#include <stack>
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
Node* insert(Node* root, int val) {
    if (root == NULL)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void convert(Node* root) {
    stack<Node*> st;
    Node* curr = root;
    Node* prev = NULL;
    while (curr != NULL || !st.empty()) {
        while (curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        if (curr->left == NULL) {
            curr->left = prev;
            curr->leftThread = true;
        }
        if (prev != NULL && prev->right == NULL) {
            prev->right = curr;
            prev->rightThread = true;
        }
        prev = curr;
        curr = curr->right;
    }
    if (prev != NULL && prev->right == NULL)
        prev->rightThread = true;
}
Node* search(Node* root, int x) {
    while (root != NULL) {
        if (root->data == x)
            return root;
        if (x < root->data) {
            if (root->leftThread)
                return NULL;
            root = root->left;
        }
        else {
            if (root->rightThread)
                return NULL;
            root = root->right;
        }
    }
    return NULL;
}
Node* successor(Node* root) {
    if (root == NULL)
        return NULL;
    if (root->rightThread)
        return root->right;
    root = root->right;
    while (root->left != NULL && !root->leftThread)
        root = root->left;
    return root;
}
Node* predecessor(Node* root) {
    if (root == NULL)
        return NULL;
    if (root->leftThread)
        return root->left;
    root = root->left;
    while (root->right != NULL && !root->rightThread)
        root = root->right;
    return root;
}
Node* minimum(Node* root) {
    while (root != NULL && root->left != NULL && !root->leftThread)
        root = root->left;
    return root;
}
void rangeQuery(Node* root, int L, int R) {
    Node* curr = NULL;
    while (root != NULL) {
        if (root->data >= L) {
            curr = root;
            if (root->leftThread)
                break;
            root = root->left;
        }
        else {
            if (root->rightThread)
                root = NULL;
            else
                root = root->right;
        }
    }
    cout << "[";
    bool first = true;
    while (curr != NULL && curr->data <= R) {
        if (!first)
            cout << ", ";
        cout << curr->data;
        first = false;
        curr = successor(curr);
    }
    cout << "]" << endl;
}
void kthSmallest(Node* root, int k) {
    Node* curr = minimum(root);
    while (curr != NULL && --k > 0)
        curr = successor(curr);
    if (curr == NULL)
        cout << "NULL" << endl;
    else
        cout << curr->data << endl;
}
int main() {
    int n, x;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = insert(root, x);
    }
    convert(root);
    int q, k, L, R;
    string op;
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == "NEXT" || op == "PREV") {
            cin >> x;
            Node* curr = search(root, x);
            Node* ans = NULL;
            if (curr != NULL) {
                if (op == "NEXT")
                    ans = successor(curr);
                else
                    ans = predecessor(curr);
            }
            cout << op << " " << x << " = ";
            if (ans == NULL)
                cout << "NULL";
            else
                cout << ans->data;
            cout << endl;
        }
        else if (op == "RANGE") {
            cin >> L >> R;
            rangeQuery(root, L, R);
        }
        else if (op == "KTH") {
            cin >> k;
            cout << "KTH " << k << " = ";
            if (k <= 0)
                cout << "NULL" << endl;
            else
                kthSmallest(root, k);
        }
    }
    return 0;
}