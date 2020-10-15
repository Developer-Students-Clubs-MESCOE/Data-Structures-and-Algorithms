/*
Beginning with an empty binary search tree, construct binary search tree by inserting the values in the order given. After constructing an binary tree-
i. 	Insert new node
ii. 	Find number of nodes in longest path / Height
iii. 	Minimum data value found in the tree
iv. 	Change a tree so that the roles of the left and right pointer are swapped at every node / Mirror Image
v. 	Search a value
*/

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

//create a structre of node
class node
{
	public:
		int data;
		node *left;	//left link
		node *right;	//right link

};

class Tree
{
public:
	int h, Flag;
	Tree()
	{
		h = 0;	//variable to find height
		Flag = 0; 	//Searching Flag
	}
	void insert(node *,node *); //function to insert node
	void disp(node *,int);  //function to display tree

	void Height(node *, int);
	void Search(node *, int);
	void Inorder(node *);
	void Mirror(node *);

};

//function to display tree
void Tree::disp(node* root,int k)
{
	int i;
	if(root)
	{
		disp(root->right, k+1);
		cout<<endl;
		for(i = 0; i< k; i++)
			cout<<' ';
		cout<<root->data;
		disp(root->left, k+1);
	}
}

//function to insert the node into tree
void Tree::insert(node *root,node *s)
{
	//insert at right
	if(s->data > root->data)
	{
		if(root->right == NULL)
			root->right = s;
		else
			insert(root->right, s);
	}

	//insert at left
	if(s->data <= root->data)
	{
		if(root->left == NULL)
			root->left = s;
		else
			insert(root->left,s);
	}
}

//Tree Traversing
void Tree::Inorder(node *T)
{
	if(T)
	{
		Inorder(T->left);
		cout<<" "<<T->data;
		Inorder(T->right);
	}

}

void Tree::Height(node* root, int k)
{
	int i;
	if(root)
	{
		if(k > h)
			h = k;

		Height(root->right, k+1);
		Height(root->left, k+1);
	}

}

void Tree::Mirror(node *root)
{
	node *temp;
	if(root)
	{
		temp=root->left;
		root->left=root->right;
		root->right=temp;

		Mirror(root->left);
		Mirror(root->right);
	}
}

void Tree::Search(node* root, int k)
{
	int i;
	if(root)
	{
		if(k == root->data)
			Flag = 1;
		else if(k < root->data)
			Search(root->left, k);
		else
			Search(root->right, k);
		
	}

}

int main()
{
	int ch,c, key;
	char temp;
	node *root,*s;
	Tree t;

	root = new node;	//allocate memory for new node
	root = NULL;	//initially root is NULL

	do{
		cout<<"\n 1. Create & Insert New Node"
		    <<"\n 2. Display tree"
		    <<"\n 3. Display-Inorder"
		    <<"\n 4. Height of the Tree"
		    <<"\n 5. Mirror Image"
		    <<"\n 6. Search a Value"
		    <<"\n 7. Exit"<<endl;
		cout<<"\n Enter your choice ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				do{
					s=new node;	//allocate memory for new node
					s->left=NULL;	//assign left child as NULL
					s->right=NULL;	//assign right child as NULL

					cout<<"\n"<<"ENTER DATA::";
					cin>>s->data;

					//check whether root is NULL
					if(root == NULL)
						root = s;
					else
						t.insert(root, s);

					cout<<"\n"<<"WANT TO ENTER MORE ELEMENTS(y/n)::";
					cin>>temp;

				}while(temp=='y');
				break;
			case 2:
				t.disp(root,1);
				break;
			case 3:
				t.Inorder(root);
				break;
			case 4:
				t.Height(root, 1);
				cout<<"\n Height of Tree : "<<t.h;
				break;
			case 5:
				t.Mirror(root);
				break;
			case 6:
				cout<<"\n Enter the value to be search : ";
				cin>>key;
				t.Search(root, key);
				if(t.Flag == 1)
					cout<<" Key Found Successfully\n";
				else
					cout<<" Key Not Found\n";
				t.Flag = 0;
				break;
			default:
				cout<<"\n You are successfully exited \n";
				break;
		}
	}while(ch != 7);

	return 0;
}
