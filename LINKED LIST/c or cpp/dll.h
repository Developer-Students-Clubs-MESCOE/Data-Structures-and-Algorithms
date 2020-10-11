#include <stdio.h>
#include <stdlib.h>
//Author: Taniya Kulkarni

//Node for Doubly linked list.
struct node 
{
    int num;
    struct node *prev, *next;
};
struct node *new, *ptr;
int size=0;

//Function to check if list is empty
void isempty(struct node *head)
{
    if (head==NULL)
    {
	printf("\n LIST IS EMPTY!\n");
        return;
    }
    return;
}



//Function to insert node at the end 
void insert_end (int item, struct node **head_ref)
{
    struct node *temp;
    new=(struct node *) malloc (sizeof(struct node));
    new->num = item;
    new->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new;
        size++;
        return;
    }
    
    else
    {
        temp = *head_ref;
        while (temp -> next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->prev = temp;
    }
    size++;
}





void display (struct node *head)
{

    if (head != NULL)
    {
        struct node *temp;
        temp=head;
        while(temp->next != NULL)
        {
            printf (" %d -> ", temp->num);
            temp= temp->next;
        }
        printf("%d ", temp->num);
    }
}


//Function to check for duplicates
void duplicates(struct node **head_ref)       
{
    struct node *temp, *copy;
    isempty(*head_ref);
    if(*head_ref != NULL)
    {
        temp = *head_ref;
        while (temp != NULL && temp->next != NULL)
        {
            ptr = temp;
            while(ptr -> next != NULL)
            {
                if(temp->num == ptr->next->num)     //If duplicate found, then delete the copy.
                {
                    copy = ptr->next;
                    ptr->next = ptr->next->next;
                    free(copy);
                }
                else
                {
                    ptr= ptr->next;
                }
            }
            temp = temp->next;
        }
        
    }
}