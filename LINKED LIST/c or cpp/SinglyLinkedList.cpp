#include <iostream>
using namespace std;
class Node{			//creating class node
	public:
		int no;
		Node *next;
};
class List{			//creating class List
	public:
		Node *head,*temp;
		void creat();
		void display();
		void insert_before();
		void insert_after();
		void delete_node();
};

void List::creat(){		//method to create linked list
	int n,i;
	cout<<"Enter number of nodes: ";
	cin>>n;
	head = new Node;
	temp=head;
	cout<<"Enter data value: "<<endl;
	cin>>head->no;
	for(i=1;i<n;i++){
		head->next=new Node;
		head = head->next;
		cout<<"Enter data value: "<<endl;
		cin>>head->no;
	}
	head->next=NULL;
}

void List::insert_after(){			//method to add node after the given node
	int key,x;
	cout<<"\nEnter the data value to be added: ";
	cin>>x;
	cout<<"Enter the data value after which you want to insert node: ";
	cin>>key;
	head=temp;
	while(head->no!=key){
		head=head->next;
	}
	Node *add=new Node;
	add->next=head->next;
	add->no=x;
	head->next=add;
	display();
}

void List::insert_before(){			//method to add node before the given node
	int key,x;
	cout<<"\nEnter the data value to be added: ";
	cin>>x;
	cout<<"Enter the data value before which you want to insert node: ";
	cin>>key;
	Node *add=new Node;
	add->no=x;
	head=temp;
	if(head->no==key){
		add->next=head;
		head=add;
		cout<<"\nThe linked list is: "<<endl;
		while(head->next!=NULL){
			cout<<head->no<<" ";
			head=head->next;
		}
		cout<<head->no;
	} else {
		while(head->next->no!=key){
			head=head->next;
		}
		add->next=head->next;
		head->next=add;
		display();
	}
}

void List::delete_node(){		//method to delete the given node
	int key,x;
	cout<<"\nEnter the data value to be deleted: ";
	cin>>key;
	head=temp;
	if(head->no==key){
		head=head->next;
		cout<<"\nThe linked list is: "<<endl;
		while(head->next!=NULL){
			cout<<head->no<<" ";
			head=head->next;
		}
		cout<<head->no;
	} else {
		while(head->next->no!=key){
			head=head->next;
		}
		if(head->next->next==NULL){
			head->next=NULL;
		} else {
			head->next=head->next->next;
		}
		display();
	}
}

void List::display(){		////method to display the linked list
	head=temp;
	cout<<"\nThe linked list is: "<<endl;
	while(head->next!=NULL){
		cout<<head->no<<" ";
		head=head->next;
	}
	cout<<head->no;
}
int main(){
	List l;		//creating object of the class List
	l.creat();
	int c=0;
	while(c!=5){
		cout<<"\n\n1. Display the linked list.\n2. Add after a node.\n3. Add before a node.\n4. Delete a node.\n5. Exit."<<endl;
		cin>>c;
		switch(c){
			case 1:
				l.display();
				break;
			case 2:
				l.insert_after();
				break;
			case 3:
				l.insert_before();
				break;
			case 4:
				l.delete_node();
				break;
			case 5:
				break;	
		}
	}
	return 0;
}
