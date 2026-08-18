#include <iostream>
using namespace std;
struct node{
        int data;
        struct node *link;
    };
int main() {
    cout << "Hello, World!" << endl;
    struct node *start, *ptr,*tmp;
    start=NULL;

    
    tmp=(struct node *)malloc(sizeof(struct node));
    start=tmp;
    int num;
    for(int i=0;i<5;i++){
        cout << "enter a number at node no : "<< i;
        cin>>num;
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data =num;
        tmp->link = start;


    }
    
    return 0;
}
