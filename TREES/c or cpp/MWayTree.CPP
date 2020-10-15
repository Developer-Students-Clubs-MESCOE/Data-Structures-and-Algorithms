//Create m-way tree and perform recursive traversal

#include<iostream.h>
#include<conio.h>

//create a structre of node
//____________________________________________
//| left * | N | E[E1, E2, .........., Em]   |
//--------------------------------------------
//left * point to left chlid
//N is number of entries
//E is array to store the entries
class node;
//Entry structure
class entry
{
public:
	int data;
	node *right;
};

//node structure
class node
{
public:
	int N;	//no of entries
	node *left;
	entry *E[10];	//4-way tree
};

class Tree
{
public:
	int m; 	//order of tree
	void insert(node *, entry *);
	void Inorder(node *);
};

//function to insert the node into tree
void Tree::insert(node *r, entry *e)
{
	//insert at left
	if(e->data < r->E[0]->data)
	{
		if(r->left == NULL)
		{
			r->left = new node;
			r= r->left;

			r->E[0] = e;
			r->N = 1;
			r->left = NULL;
		}
		else
			insert(r->left, e);
	}
	//insert at right
	else
	{
		int i, count = 0;
		for(i = 1 ; i<r->N; i++)
		{
			if(e->data < r->E[i]->data)
			{
				count++; // condition true

				if(r->E[i-1]->right == NULL)
				{
					r->E[i-1]->right = new node;
					r= r->E[i-1]->right;

					r->E[0] = e;
					r->N = 1;
					r->left = NULL;
				}
				else
					insert(r->E[i-1]->right, e);

				break;
			}
		}
		if(count == 0) //if condition false
		{
			if(r->N != m)	//m-way search tree
			{
				r->E[r->N] = e;
				r->N += 1;
			}
			else
			{
				if(r->E[i-1]->right == NULL)
				{
					r->E[i-1]->right = new node;
					r= r->E[i-1]->right;

					r->E[0] = e;
					r->N = 1;
					r->left = NULL;
				}
				else
					insert(r->E[i-1]->right, e);
			}
		}
	}
}

void Tree::Inorder(node *T)
{
	int i;
	if(T)
	{
		Inorder(T->left);
		for(i = 0; i<T->N; i++)
		{
			cout<<" "<<T->E[i]->data;
			if(T->E[i]->right)
				Inorder(T->E[i]->right);
		}
	}

}

void main()
{
	int ch,c;
	char temp;
	node *r;
	entry *e;
	Tree t;

	r = new node; //allocate memory for new node
	r->E[0] = NULL;	//initially root is NULL

	clrscr();

	cout<<"\n Enter the order of tree : ";
	cin>>t.m;
	do{
		e = new entry;	//allocate memory for new node
		e->right=NULL;	//assign right child as NULL

		cout<<"\n"<<"ENTER DATA::";
		cin>>e->data;

		//check whether root is NULL
		if(r->E[0] == NULL)
		{
			r->E[0] = e;
			r->N = 1;
			r->left = NULL;
		}
		else
			t.insert(r, e);

		cout<<"\n"<<"WANT TO ENTER MORE ELEMENTS(y/n)::";
		cin>>temp;

	}while(temp=='y');
	cout<<"\n Inorder sequence :";
	t.Inorder(r);

	getch();
}
