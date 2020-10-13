#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
};

//Traversing through the circular linked list
void circular_ll_traversal(Node* head){
    Node* p = head;
    do{
        cout<<p->data<<" ";
        p=p->next;
    }while(p!=head);
}
//Inserting at first
Node* insertAtFirst(Node* head, int data){
    Node* zero = new Node();
    zero->data=data;
    
    Node* p=head;
    while(p->next!=head){
        p=p->next;
    }
    p->next = zero;
    zero->next = head;
    head= zero;
    return head;
    
}
//Inserting at the last
Node* insertAtLast(Node* head,int data){
    Node* sixth = new Node();
    sixth->data=data;
    
    Node* p = head;
    while(p->next!=head){
        p=p->next;
    }
    p->next=sixth;
    sixth->next=head;
    return head;
    
}
//Inserting at a specific index
Node* InsertAtIndex(Node* head,int data,int index){
    Node* between = new Node();
    between->data=data;
    int i=0;
    Node* p=head;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    between->next = p->next;
    p->next = between;
    return head;
    
}


int main(){
    Node* head=new Node();
    Node* second =new Node();
    Node* third =new Node();
    Node* fourth =new Node();
    Node* fifth =new Node();
    
    head->data=23;
    head->next=second;
    
    second->data=12;
    second->next=third;
    
    third->data=34;
    third->next=fourth;
    
    fourth->data=56;
    fourth->next=fifth;
    
    fifth->data=90;
    fifth->next=head;
    
    cout<<"Circular linked list before Insertion\n";
    circular_ll_traversal(head);
    cout<<"\n";
    
    //head=insertAtFirst(head, 45);
    //cout<<"\n";
    //circular_ll_traversal(head);
    
    //head = insertAtLast(head,53);
    head = InsertAtIndex(head,44,3);
    
    cout<<"Circular linked list after Insertion\n";
    circular_ll_traversal(head);
    cout<<"\n";
    
    return 0;
     
}
