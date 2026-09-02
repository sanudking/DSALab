#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
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
    
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* node2=head;
    head=elem;
    elem->next=node2;
    temp->next=head;
}
void insert_at_end(Node* &head,int data){
    Node* elem=new Node(data);
    Node*temp=head;
    
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* node2=head;
    temp->next=elem;
    elem->next=node2;
    
}
void insert_at_pos(Node* &head,int data,int pos){
    Node* elem=new Node(data);
    Node*temp=head;
    int i=1;
    while(i!=pos){

        temp=temp->next;
        i++;
    }
    elem->next=temp->next;
    temp->next=elem; 
}
void delete_node(Node * &head,int pos){
    Node*temp=head;
    if(pos==1){
        
    
        while(temp->next!=head){
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;

    }
    else{
        int i=1;
    while(i<pos-1){

        temp=temp->next;
        i++;
    }
        temp->next=temp->next->next;
    }
}


int main() {
    int n;
    cout<<"Enter size of linked list : ";
    cin>>n;
    Node*head=nullptr;
    Node*tail=nullptr;
        
    for(int i=0;i<n;i++){
        int val;
        cout<<"Enter element no "<<i<<": ";
        cin>>val;
        Node * tmp=new Node(val);
        if(head==nullptr){
            head=tmp;
            tail=tmp;
            // head->data=tmp->data;
        }
        else{

            tail->next=tmp;
            tail=tmp;
        }
        tail->next=head;
    }
    cout<<"Insert at begin : ";

    insert_at_begin(head,100);
    print(head);
    cout<<"\n";
    cout<<"Insert at end : ";
    insert_at_end(head,200);
    print(head);
    cout<<"\n";
    cout<<"Insert at pos : ";
    insert_at_pos(head,300,2);
    print(head);
    cout<<"\n";
    cout<<"Delete at begin : ";
    delete_node(head,1);
    print(head);
    cout<<"\n";
    cout<<"Delete at pos : ";
    delete_node(head,3);
    print(head);
    return 0;
}
