//Create B-tree and perform recursive traversal
//Reference Book: "Data Structures : A psudocode approach through C++"
//		   by B. Fourozn

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
	entry *insert(node *, entry *, entry *);
	node *insertEntry(node *, entry *);
	entry *split(node *, entry *);
	int isleaf(node *);
	void Inorder(node *);
};
node *Tree::insertEntry(node *r, entry *e)
{
	//sort the entries
	int i;
	entry *temp;
	temp = e;
	for(i = 0; i<r->N; i++)
	{
		if(e->data < r->E[i]->data)
		{
			temp = r->E[i];
			r->E[i] = e;
			e = temp;
		}
	}
	r->E[i] = temp;
	r->N += 1;
	return r;
}

//function to split the node
entry *Tree::split(node *r, entry *e)
{       /*
	//find min entries
	int min_entry;
	if(m%2 == 0)	//if order of tree is even
		min_entry = (m/2)-1;
	else
		min_entry = m/2;
	*/
	//split root node (r) into n1 & n2
	node *n2;
	//n1 = new node;
	//n1->left = NULL;
	n2 = new node;
	n2->N = 0;
	n2->left = NULL;

	//sort the entries
	entry *s[10];
	int i;
	for(i = 0; i<m-1; i++)
	{
		if(e->data < r->E[i]->data)
		{
			s[i] = e;
			e = r->E[i];
		}
		else
			s[i] = r->E[i];
	}
	s[i] = e;

	//find the middle entry
	entry *mid;
	mid = s[m/2];

	//reinitialize the root
	for(i = 0; i<m; i++)
		r->E[i] = NULL;
	r->N = 0;
	//keep 1st half entries in root & 2nd half entries in node n2
	for(i = 0; i<m/2; i++)
	{
		r->E[i] = s[i];
		r->N += 1;
		n2->E[i] = s[i+(m/2)+1];
		n2->N += 1;
	}
	mid->right = n2;	//point to right subtree;

	//now update root entries & store middle entry
	//for(i = 0; i<m; i++)
	//	r->E[i] = NULL;

	//r->left = n1;		//left node
	//r->E[0] = s[m/2];
	//r->E[0]->right = n2;    //right node
	//r->N = 1;


	return mid;
}
//function to insert the node into tree
entry *Tree::insert(node *r, entry *mid, entry *e)
{
	//insert at left
	if(e->data < r->E[0]->data)
	{
		if(r->left == NULL)
		{
			//if node not full
			if(r->N != m-1)
				r = insertEntry(r, e);
			else
				mid = split(r, e);
		}
		else
			mid = insert(r->left, mid, e);
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
					//if node not full
					if(r->N != m-1)
						r = insertEntry(r, e);
					else
						mid = split(r, e);
				}
				else
					mid = insert(r->E[i-1]->right, mid, e);

				break;
			}
		}
		if(count == 0) //condition false
		{
			//if node not full
			if(i != m-1)	//m-way search tree
			{
				if(r->E[i-1]->right == NULL)
					r = insertEntry(r, e);
				else
					mid = insert(r->E[i-1]->right, mid, e);
			}
			else
				mid = split(r, e);
		}
	}
	if(mid)	//mid != NULL
	{
		if(isleaf(r) == 1)//is not leaf node
		{
			if(r->N != m-1)
			{
				r = insertEntry(r, mid);
				mid = NULL;
			}
			else
				mid = split(r, mid);
		}
	}

	return mid;
}
int Tree :: isleaf(node *r)
{
	int i;
	if(r->left)
		return 1;
	for(i = 0; i<r->N; i++)
	{
		if(r->E[i]->right)
			return 1;
	}
	return 0;
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
	node *root, *r;
	entry *e, *mid;
	Tree t;

	mid = NULL;
	root = new node; //allocate memory for new node
	root->E[0] = NULL;	//initially root is NULL


	clrscr();

	cout<<"\n Enter the order of tree : ";
	cin>>t.m;
	do{
		r = root;
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
		{
			mid = t.insert(r, mid, e);
			if(mid)	//mid != NULL
			{
				root = new node;
				root->left = r;
				root->E[0] = mid;
				root->N = 1;
				mid = NULL;
			}

		}
		//root = r;
		cout<<"\n"<<"WANT TO ENTER MORE ELEMENTS(y/n)::";
		cin>>temp;

	}while(temp=='y');
	cout<<"\n Inorder sequence :";
	t.Inorder(root);

	getch();
}

