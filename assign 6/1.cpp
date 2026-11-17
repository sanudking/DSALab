#include <iostream>
using namespace std;
struct Tree{
    
    int val;
    Tree*left;
    Tree*right;
    
    Tree(int x){
        val=x;
        left=NULL;
        right=NULL;
    }
};
bool isMirror(Tree* tl,Tree* tr){
    if(tr==nullptr && tl==nullptr) return true;
    if(tr==nullptr || tl ==nullptr) return false;
    return (tl->val==tr->val) && isMirror(tl->left,tr->right) && isMirror(tl->right,tr->left);

}
bool isSymmetric(Tree*root){
    if(root==nullptr) return true;
    return isMirror(root->left,root->right);
}
int main() {
    Tree *root= new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(2);
    root->left->left = new Tree(37);
    root->left->right = new Tree(4);
    root->right->left = new Tree(4);
    root->right->right = new Tree(3);

    if(isSymmetric(root)){
        cout<<"\nSymmetric";

    }else{
        cout<<"\n Not symmetric";
    }


    return 0;
}
