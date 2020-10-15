// binary search tree with all type of recursive and non-recursive traversal

#include <iostream>
using namespace std;

class Tree
{
    char data;
    Tree* left;
    Tree* right;
    public: 
        Tree* create(char ele);
        Tree *construct(char p[]);
        void inorder(Tree* base);
        void preorder(Tree*);
        void postorder(Tree*);
        void NRinorder(Tree* base);
        void NRpreorder(Tree*);
        void NRpostorder(Tree*);
};

class Stack
{
    public:
    Tree *t_obj;
    Stack* Stack_link;
    int flag;

    Stack* push(Tree *, Stack *, int);
    Stack* pop(Stack* top);
};

Stack* Stack :: push(Tree *ele, Stack *top, int f)
{
    Stack* newnode = new Stack;
    newnode->flag= f;
    newnode->t_obj = ele;
    newnode ->Stack_link = NULL;

    if(top == NULL)
    {
      top = newnode;  
    }
    else
    {
      newnode->Stack_link = top;
      top = newnode;
    }
    return top;
}

Stack* Stack :: pop(Stack* top)
{
  Stack *temp = top;
  top = top->Stack_link;
  delete temp;
  return top;
}

Tree * Tree :: create(char ele)
{
  Tree* newnode = new Tree;
  newnode -> data = ele;
  newnode -> left = NULL;
  newnode -> right = NULL;
  return newnode;
}

Tree * Tree :: construct(char p[])
{
    Stack *top = NULL;
    Tree *temp;
    int i=0;
    while(p[i] != '\0') 
    {
        if(isalnum(p[i]))
        {
            temp = create(p[i]);
            top = top-> push(temp, top,0);
        }
        else
        {
            temp = create(p[i]);
            temp->right = top->t_obj;
            top = top->pop(top);

            temp->left = top->t_obj;
            top = top->pop(top);

            top = top->push(temp, top,0);
        }
        i++;
    }
    temp = top->t_obj;
    top = top->pop(top);
    return temp;
}

void Tree :: inorder(Tree *base)
{
    if(base == NULL)
        return;
    inorder(base->left);
    cout<<base->data;
    inorder(base->right);
}

void Tree :: preorder(Tree *base)
{
	  if(base==NULL)
		  return;
		cout<<base->data;
		preorder(base->left);
		preorder(base->right);
}

void Tree::postorder(Tree *base)
{
	  if(base==NULL)
		  return;
	  postorder(base->left);
		postorder(base->right);
		cout<<base->data;
}

void Tree::NRinorder(Tree *base){
	  Stack *top=NULL;
		Tree *current=base;
		while(current!=NULL || top!=NULL){
			while(current!=NULL){
			  top=top->push(current,top,0);
			  current=current->left;
			}

		if(current==NULL  && top!=NULL){
			current=top->t_obj;
			top=top->pop(top);
			cout<<current->data;
			current=current->right;
		}
		else	
			break;
		}
}

void Tree::NRpreorder(Tree *base){
	  Stack *top=NULL;
		Tree *current=base;
		while(current!=NULL || top!=NULL){
			while(current!=NULL){
        cout<<current->data;
			  top=top->push(current->right,top,0);
			  current=current->left;
			}

		if(current==NULL  && top!=NULL){
			current=top->t_obj;
			top=top->pop(top);
		}
		else	
			break;
		}
}

void Tree::NRpostorder(Tree *base){
	  Stack * top=NULL;
    Tree * curr=base;
    int flag;
    do
    {   while(curr!=NULL)
        {   top=top->push(curr,top,0);
            curr=curr->left;
        }
        flag=top->flag;
        curr=top->t_obj;
        top=top->pop(top);
        if(flag==1)
        {   cout<<curr->data;
            curr=NULL;
        }
        else
        {   top=top->push(curr,top,1);
            curr=curr->right;
        }
    }
    while(top!=NULL);
}

int main() 
{   
    char postfix[20];
    Tree obj;
    Tree *root = NULL;
    int choice,op;
    
    cout<<"Enter postfix expression: ";
    cin>>postfix;
    root=obj.construct(postfix);
        do{   
            cout<<"\n Traversal of choice - "<<endl;
            cout<<" 1.inorder traversal"<<endl;
            cout<<" 2.preorder traversal"<<endl;
            cout<<" 3.postorder traversal"<<endl;
            cout<<" 0.exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
              switch(choice)
                {
                case 1:
                    cout<<"\n Method of choice - "<<endl;
                    cout<<" 1.Recursive"<<endl;
                    cout<<" 2.Non Recursive"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>op;
                    switch(op)
                    {
                    case 1:
                        cout<<"Recursive inorder traversal: ";
                        obj.inorder(root);
                        break;
                    case 2:
                        cout<<"Non-recursive inorder traversal: ";
                        obj.NRinorder(root);
                        break;
                    }
                    break;
                case 2:
                    cout<<"\n Method of choice - "<<endl;
                    cout<<" 1.Recursive"<<endl;
                    cout<<" 2.Non Recursive"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>op;
                    switch(op)
                    {
                    case 1:
                        cout<<"Recursive preorder traversal: ";
                        obj.preorder(root);
                        break;
                    case 2:
                        cout<<"Non-recursive preorder traversal: ";
                        obj.NRpreorder(root);
                        break;
                    }
                    break;
                case 3:
                    cout<<"\n Method of choice - "<<endl;
                    cout<<" 1.Recursive"<<endl;
                    cout<<" 2.Non Recursive"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>op;
                    switch(op)
                    {
                    case 1:
                        cout<<"Recursive postorder traversal: ";
                        obj.postorder(root);
                        break;
                    case 2:
                        cout<<"Non-recursive postorder traversal: ";
                        obj.NRpostorder(root);
                        break;
                    }
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    cout<<"Enter valid choice"<<endl;
                }
            } while(choice!=0);
    return 0;
}