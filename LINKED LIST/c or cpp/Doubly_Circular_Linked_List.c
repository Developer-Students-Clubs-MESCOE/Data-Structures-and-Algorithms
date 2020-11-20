#include<stdio.h>
#include<stdlib.h>
int get_length();
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=0,*tail=0,*newnode;
int i,n;

void create()
{
    printf("enter the number of nodes you want\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
            head->prev=head;
            tail->next=tail;
        }
        else
        {
            newnode->prev=tail;
            newnode->next=head;
            tail->next=newnode;
            head->prev=newnode;
            tail=newnode;  
        }
    }
    
}
void display()
{
    struct node *temp;
    int count=1,length;
    temp=head;
    if(head==0)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("your nodes are\n");
        while(temp!=tail)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
        count++;
    }
        printf("%d\n",temp->data);
        printf("the number of nodes present-->%d\n",count);    
    }
}
void insert_beg()
{
    printf("enter the number of nodes you want\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
            head->prev=head;
            head->next=head;
        }
        else
        {
            newnode->next=head;
            newnode->prev=tail;
            head->prev=newnode;
            tail->next=newnode;
            head=newnode;  
        } 
    }
}
void insert_end()
{
    printf("enter the number of nodes you want at the end\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter data\n");
        scanf("%d",&newnode->data);
        if(head==0)
        {
            head=tail=newnode;
            head->prev=head;
            head->next=head;
        }
        else
        {
            newnode->prev=tail;
            newnode->next=head;
            tail->next=newnode;
            head->prev=newnode;
            tail=newnode;
        } 
    }
}
void insert_any()
{
    struct node *temp,*traverse;
    int position,internal_counter=1;
    temp=head;
    traverse=head;
    while(traverse!=tail)
    {
        traverse=traverse->next;
        internal_counter++;
    }
    printf("enter the position where you want to insert the node\n");
    scanf("%d",&position);
    for(i=1;i<position-1;i++)
    {
        temp=temp->next;
    }
    if(position==1)
    {
        insert_beg();
    }
    else if(position<1||position>internal_counter)
    {
        printf("enter valid position less than -->%d but not less than 1",internal_counter);
    }
    else
    {
        printf("enter the number of nodes you want to insert\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            newnode=(struct node *)malloc(sizeof(struct node));
            printf("enter data\n");
            scanf("%d",&newnode->data);
            if(head==0)
            {
                 head=tail=newnode;
                 head->prev=head;
                 head->next=head;
            }
            else
            {
                newnode->prev=temp;
                newnode->next=temp->next;
                temp->next->prev=newnode;
                temp->next=newnode;
                temp=newnode;  
            }  
        } 
    }
}
void delete_beg()
{
    struct node *temp;
    temp=head;
    if(head==0)
    {
        printf("list is empty\n");
    }
    else if(head==head->next)
    {
        head=tail=0;
        free(temp);
        printf("Operation executed\n");
    }
    else
    {
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
        printf("A node has been deleted from the begginning\n");
    }
}
void delete_end()
{
    struct node *temp;
    temp=tail;
    if(head==0)
    {
        printf("list is empty\n");
    }
    else if(head==head->next)
    {
        head=tail=0;
        free(temp);
        printf("Operation executed\n");
    }
    else
    {
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
        printf("A node has been deleted from the end\n");
    }   
}
void delete_any()
{
    struct node *current;
    int pos,i,length;
    current=head;
    length=get_length();
    printf("Enter the position you want to delete\n");
    scanf("%d",&pos);
    if(pos<1||pos>length)
    {
        printf("position is invalid enter something less than or equal to %d but greater than 0",length);
    }
    else if(pos==1)
    {
        delete_beg();
    }
    else if(pos==length)
    {
        delete_end();
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            current=current->next;
        }
        current->prev->next=current->next;
        current->next->prev=current->prev;
        free(current);
        printf("Node Number %d has been deleted\n",pos);
    } 
}
int get_length()
{
    int counter=1;
    struct node *traverse;
    traverse=head;
    while(traverse!=tail)
    {
        traverse=traverse->next;
        counter++;
    }
    return counter;
}
void main()
{
    int a;
    while(a!=6)
    {
        printf("\nType 1 to create doubly circular linked list\nType 2 to display that list\nType 3 to insert anywhere\nType 4 to insert at the end\nType 5 to delete any node\nType 6 to exit\n");
        scanf("%d",&a);
        switch (a)
        {
        case 1:
        create();
        break;
        
        case 2:
        display();
        break;

        case 3:
        insert_any();
        break;

        case 4:
        insert_end();
        break;

        case 5:
        delete_any();
        break;
        }
    }

}