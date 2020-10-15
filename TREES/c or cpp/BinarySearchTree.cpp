#include <iostream>
using namespace std;

class bst{
  int data;
  bst* left;
  bst* right;
  public :
  bst* create(int);
  bst* insert(bst*);
  void search (bst*,int);
  void inorder(bst*);
  bst* del (bst*,int);
};

bst* bst::create(int key){
  bst *newnode = new bst;
  newnode->data=key;
  newnode->left=NULL;
  newnode->left=NULL;
  return newnode;
}

void bst::inorder(bst *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout<<root->data<<"  ";
        inorder(root->right);
    }
}



bst * bst::insert(bst *root)
{
    int ele;
    cout<<"\ninsert the element: ";
    cin>>ele;
    bst *current,*parent;
    bst *newnode=create(ele);
    if(root==NULL)
    {
        root=newnode;
    }
    else
    {
        current=root;
        while(current!=NULL && current->data!=ele)
        {
            parent=current;
            if(ele<current->data)
            {
                current=current->left;
            }
            else
            {
                current=current->right;
            }
        }

        if(current==NULL)
        {
            if(ele>parent->data)
            {
                parent->right=newnode;
            }
            else
            {
                parent->left=newnode;
            }
        }

        else

        {
            cout<<"\nelement already exit in tree"<<endl;
            return root;
        }

    }
    return root;
}

void bst::search(bst *root,int ele)
{
    bst *curr;
    curr=root;
    while(curr!=NULL && curr->data!=ele)
    {
        if(ele<curr->data)
        {
            curr=curr->left;
            
        }
        else
        {
            curr=curr->right;
        }
    }
    if(curr==NULL)
    {
        cout<<"entered element is not present"<<endl;
    }
    else if(curr->data==ele)
    {
        cout<<"entered element is present"<<endl;
        cout<<"\n DATA- "<<curr->data<<"\t Left pointer- "<<curr->left<<"\t Right pointer- "<<curr->right;
    }
}

bst* bst::del(bst *root,int key)
{
    if(root==NULL)
        cout<<"tree empty";
    else
    {
        bst *curr, *parent,*gp;
        curr=root;
        while(curr !=NULL && curr->data!=key)
        {
            parent=curr;
            if(key<curr->data)
            {
                curr=curr->left;
            }
            else
                curr=curr->right;
        }
        if(curr==NULL)
        {
            cout<<"element not present";
        }
        else
        {
            if(curr->left==NULL && curr->right==NULL)
            {
                if(curr!=root)
                {
                    if(parent->left==curr)
                        parent->left=NULL;
                    else
                        parent->right=NULL;
                }
                else
                    root=NULL;

            }
            if(curr->left!=NULL && curr->right!=NULL)
            {
                gp=curr;
                curr=curr->left;
                parent=curr;
                while(curr->right!=NULL)
                {
                    parent=curr;
                    curr=curr->right;
                }
                gp->data=curr->data;
                if(curr->left!=NULL)
                    parent->right=curr->left;
                else
                  {
                    if(parent==curr){
                      gp->left=NULL;
                    }
                    else{
                    parent->right=NULL;
                    }
                  }
            }
            if(curr->left!=NULL)
            {
                if(parent->right==curr)
                    parent->right=curr->left;
                else
                    parent->left=curr->left;
            }
            if(curr->right!=NULL)
            {
                if(parent->right==curr)
                    parent->right=curr->right;
                else
                    parent->left=curr->right;
            }
        cout<<"\n Element deleted succesfully";
        }
    }
    return root;
}

int main()
{
    bst *root=NULL;
    bst tr;
    int choice,num,instance,delin;
  
  do{   
            cout<<"\n Binary search tree - "<<endl;
            cout<<" 1.insert"<<endl;
            cout<<" 2.traverse"<<endl;
            cout<<" 3.search"<<endl;
            cout<<" 4.delete"<<endl;
            cout<<" 0.exit"<<endl;
            cout<<"Enter your choice: ";
            cin>>choice;
              switch(choice)
                {
                case 1:
                    cout<<"\n How many element you want to insert "<<endl;
                    cin>>num;
                    for(int i=0;i<num;i++){
                      root=tr.insert(root);
                    }
                    break;
                case 2:
                    cout<<"\n Inorder Traversal "<<endl;
                    tr.inorder(root);
                    break;
                case 3:
                    cout<<"\n which element you want to search "<<endl;
                    cin>>instance;
                    tr.search(root, instance);
                    break;
                case 4:
                    cout<<"\n which element you want to delete "<<endl;
                    cin>>delin;
                    tr.del(root,delin);
                    break;
                case 0:
                    exit(0);
                    break;
                default:
                    cout<<"Enter valid choice"<<endl;
                }
            } while(choice!=0);

}