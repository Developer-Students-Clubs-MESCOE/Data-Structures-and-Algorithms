#include<iostream>
#include<stack>
using namespace std;
class Btree
{
 typedef struct node
 {
     int data;
     struct node *right,*left;
 }node;
   public:
node *root,*temp;
Btree()
{
  root=new node;
  root=NULL;
}   
void create()
{
  temp=new node;
  cout<<"\n Enter the data:";
  cin>>temp->data;
  temp->left=temp->right=NULL;
  if(root==NULL)
  {
    root=temp;
  }
  else
  {
    insert(root,temp);
   }
 }
 void insert(node *root,node *temp)
 {
   char ch;
   cout<<"do you want to enter"<<temp->data<<"as left or right child of"<<root->data<<":";
   cin>>ch;
   if(ch=='l')
   {
     if(root->left==NULL)
     {
        root->left=temp;
     }
    else 
    {
       insert(root->left,temp);
    }  
   } 
  else 
  {
    if(root->right==NULL)
    {
      root->right=temp;
    }   
    else 
    {
     insert(root->right,temp);
     }
   }
 }    
 
void postorder_recursive(node *root)
{
  if(root!=NULL)
  {
    postorder_recursive(root->left);
    postorder_recursive(root->right);
    cout<<"\t"<<root->data;
  } 
}
void postorder_nonrecursive(node *root)
{
  if(!root)
  {
     cout<<"empty";
     stack<node *>s;
     stack<node *>p;
     s.push(root);
     while(!s.empty()) 
     {
       node *cur=s.top();
       p.push(cur);
       s.pop();
       if(cur->left)
       {
         s.push(cur->left);
       }
       if(cur->right)
       {
         s.push(cur->right);
       }
     }
     while(!p.empty())
     {
       cout<<"\t"<<p.top()->data;
       p.pop();
     }
}
}
void display(node* root,int space)
{
    if(root==NULL)
    return;
    space+=3;
    display(root->right,space);
    cout<<"\n";
    for(int i=3;i<=space;i++)
   {
     cout<<"   ";
   }
   cout<<root->data<<"\n";
   display(root->left,space);
}
};
int main()
{
     Btree b;
     int ch;
     do
     {
        b.create();
        cout<<"\n do you want to insert more element 0 OR 1 :";
        cin>>ch;
      }while(ch!=0);
      b.display(b.root,0);
      cout<<"recursive post order is:";
      b.postorder_recursive(b.root);
      cout<<"non recursive post order is:";
      b.postorder_nonrecursive(b.root);
      return 0;
}
          
    
      
      
       
       
       
       
       
         
