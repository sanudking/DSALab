#include <iostream>

struct Node {
    int data;  
    Node* next; 

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);

    head->next = second;   
    second->next = third;  
    third->next = fourth;  
    fourth->next = fifth;  
    std::cout << "Linked List of 5 elements: ";
    printList(head);
    std::cout<<"\n";

    //insert at start
    Node* tmp= new Node(100);
    tmp->next=head;
    head=tmp;
    std::cout << "Linked List of elements after adding at start: ";
    printList(head);
        std::cout<<"\n";


    //insert at end
    Node* tmp2 =new Node(200);
    Node *ptr= head;

    while(ptr->next !=nullptr){
        ptr=ptr->next;
    }
    ptr->next=tmp2;
    std::cout << "Linked List of elements after adding at end: ";
    printList(head);
        std::cout<<"\n";

    //insert at pos given
    int pos;
    std::cout<<"enter a position to add : ";
    std::cin>>pos;
    Node* tmp3 =new Node(300);
    Node *ptr2= head;

    for(int i=1;i<pos-1;i++){
        ptr2=ptr2->next;
    }
    tmp3->next=ptr2->next;
    ptr2->next=tmp3;

    
    std::cout << "Linked List of elements after adding at pos " << pos<<" : ";
    printList(head);
        std::cout<<"\n";

    //delete
    int pos2;
    std::cout<<"enter a position to delete : ";
    std::cin>>pos2;
    if (pos2 == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } 
    else{
        Node *ptr3=head;
        for(int i=1;i<pos2-1;i++){
            ptr3=ptr3->next;
        }
    ptr3->next=ptr3->next->next;
    }
    
    std::cout << "Linked List of elements after adding deleting pos " << pos2<<" : ";
    printList(head);
    std::cout<<"\n";

    
    





    


    return 0;
}
