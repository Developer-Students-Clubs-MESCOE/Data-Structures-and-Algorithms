// Creating binary tree using non-recursive method

#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
//create a structre of node
class node
{
	public:
		char data;
		int flag;
		node *left;	//left link
		node *right;	//right link

};

class Tree
{
public:
	node *data[30];	//stack array for storing nodes
	int top;	//top value of stack

	//initialize the stack
	Tree()
	{
		top =- 1;
	}

	//check for empty stack
	int empty()
	{
		if(top == -1)	//empty condition for stack
			return 1;
		else
			return 0;
	}

	//push data into stack
	void push(node *p)
	{
		data[++top] = p;	//store node into stack
	}

	//remove data from stack
	node *pop()
	{
		return(data[top--]);	//remove node from stack
	}

	void insert(node *,node *); //function to insert node
	void disp(node *, int);  //function to display tree

	void Preorder(node *);
	void Inorder(node *);
	void Postorder(node *);
	node *constructTree(char postfix[]);
	bool isOperator(char c);
};

// A utility function to check if 'c'
// is an operator
bool Tree :: isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return true;
    return false;
}

// Returns root of constructed tree for given
// postfix expression
node* Tree :: constructTree(char postfix[])
{
    	node *t, *t1, *t2;
 
    	// Traverse through every character of
    	// input expression
    	for (int i=0; i<strlen(postfix); i++)
    	{
        	// If operand, simply push into stack
        	if (!isOperator(postfix[i]))
        	{
            		t = new node;
			t->data =postfix[i];
			t->left=NULL;
			t->right=NULL;
            		push(t);
        	}
        	else // operator
        	{
            		t = new node;
			t->data =postfix[i];
			t->left=NULL;
			t->right=NULL;
 
            		// Pop two top nodes
            		t1 = pop(); 	// Store top
            		//st.pop();      // Remove top
            		t2 = pop();
            		//st.pop();
 
            		//  make them children
            		t->right = t1;
            		t->left = t2;
 
            		// Add this subexpression to stack
            		push(t);
        	}
    	}
 
    	//  only element will be root of expression
    	// tree
    	t = pop();
    	//st.pop();
 
    	return t;
}

//function to display tree
void Tree::disp(node* root, int k)
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

void Tree :: Preorder(node *t)
{
	//search toward left
	while(t)
	{
		cout<<" "<<t->data;	//display root node
		push(t);		//push data into stack
		t=t->left;              //move to left
	}

	//search towards right
	while(!empty())
	{
		t=pop();	//remove data from stack
		t=t->right;     //take right child of node

		//again search for left child
		while(t)
		{
			cout<<" "<<t->data;	//display root node
			push(t);		//push into stack
			t=t->left;		//move to left
		}
	}
}

void Tree :: Inorder(node *t)
{
	//search toward left
	while(t)
	{
		push(t);		//push data into stack
		t = t->left;              //move to left
	}

	//search towards right
	while(!empty())
	{
		t = pop();	//remove data from stack
		cout<<" "<<t->data;	//display root node
		t = t->right;     //take right child of node

		//again search for left child
		while(t)
		{
			push(t);		//push into stack
			t=t->left;		//move to left
		}
	}
}

void Tree :: Postorder(node *t)
{
	//search toward left
	while(t)
	{
		push(t); 	//push data into stack
		t = t->left;    //move to left
	}

	//search towards right
	while(!empty())
	{
		t = pop();			//remove data from stack

		if(t->flag == 1)		//check for processed node
			cout<<" "<<t->data;
		else if(t->right == NULL)	//check right link of node
			cout<<" "<<t->data;	//display root node
		else
		{
			push(t);        //push same node into stack
			t->flag = 1;	//set as a processed node

			t = t->right;   //take right child of node

			//again search for left child
			while(t)
			{
				push(t);		//push into stack
				t=t->left;		//move to left
			}
		}
	}
}

int main()
{
	char ch;
	node *root,*s;
	Tree t;
	root=NULL;

	char postfix[] = "ab+ef*g*-";
    	root = t.constructTree(postfix);
    	
	cout<<"\n The Expression tree is"<<endl;
	//cout<<"\n Add \t node \t left \t right"<<endl;
	t.disp(root, 1);

	cout<<"\n\n Pre-order Traversing is :";
	t.Preorder(root);

	cout<<"\n\n In-order Traversing is :";
	t.Inorder(root);

	cout<<"\n\n Post-order Traversing is :";
	t.Postorder(root);
	cout<<endl;
	return 0;
}

