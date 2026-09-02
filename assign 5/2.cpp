#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
    Node(){
        data=0;
        next=nullptr;
    }
};
void print(Node *head){
    Node*temp=head;
    do{
         cout<<temp->data<<" ";
        temp=temp->next;
    }
    while(temp!=head);
    
}
void insert_at_begin(Node* &head,int data){
    Node* elem=new Node(data);
    Node*temp=head;
    
    elem->next=head;
    elem->prev=head->prev;
    head->prev->next=elem;
    head=elem;
}
    
    
void insert_at_end(Node* &head,int data){
    Node* elem=new Node(data);
    Node*temp=head;
    
    head->prev->next=elem;
    elem->next=head;
    elem->prev=head->prev->prev;
    

}

int main() {
    cout << "Hello, World!" << endl;
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;
    head->prev=fifth;   
    second->next = third;
    second->prev=head;  
    third->next = fourth;  
    third->prev=second;
    fourth->next = fifth;
    fourth->prev=third;  

    cout<<"Insert at begin : ";

    insert_at_begin(head,100);
    print(head);
    cout<<"\n";
    cout<<"Insert at end : ";
    insert_at_end(head,200);
    print(head);




    return 0;
}
