//Header file for Stack and Queue
//Auhtor: Taniya Kulkarni

#include <stdio.h>
#include <stdlib.h>

//Common node for Stack and Queue
struct node
{
    int num;
    struct node *ptr;
};


//STACK OPERATIONS

struct node *top;

void create_stack()	//Function to create Stack
{
    top= NULL;
    printf("\n Stack has been created \n");
}

void push(int element)	//Function to push elements into Stack
{
    if(top== NULL)
    {
        top= (struct node*)malloc(1*sizeof(struct node));
        top->ptr= NULL;
        top->num= element;
    }
    
    else
    {
        struct node *temp;
        temp= (struct node*)malloc(1*sizeof(struct node));
        temp->ptr= top;
        temp->num=element;
        top=temp;
    }
    printf("\n %d HAS BEEN PUSHED INTO THE STACK!\n", element);
}

void pop()	//Function to pop elements from Stack
{
    struct node *temp;
    temp=top;
    if(temp==NULL)
    {
        printf("\nSTACK IS EMPTY!\n");
    }
    else
    {
        int delete_num= temp->num;
        top=top->ptr;
        printf("\n %d HAS BEEN POPPED FROM THE STACK!\n", delete_num);
    }
}

void stack_display()	//Function to display contents in Stack
{
    struct node *temp;
    temp=top;
    if(temp==NULL)
    {
        printf("\nSTACK IS EMPTY!\n");
        return;
    }
    printf(" \nELEMENTS IN STACK: \n");
    while(temp!=NULL)
    {
        printf("%d ", temp->num);
        temp=temp->ptr;
    }
    printf("\n");
}




//QUEUE OPERATIONS

struct node *front, *rear;

void create_queue()	//Function to create Queue
{
    front= NULL;
    rear= NULL;
    printf("\n Queue has been created \n");
}

void enqueue(int element)	//Function to insert elements into queue
{
    if(rear== NULL)
    {
        rear= (struct node*)malloc(1*sizeof(struct node));
        rear->ptr= NULL;
        rear->num= element;
        front=rear;
    }
    
    else
    {
        struct node *temp;
        temp= (struct node*)malloc(1*sizeof(struct node));
        rear->ptr= temp;
        temp->num=element;
        temp->ptr= NULL;
        rear=temp;
    }
    printf("\n %d HAS BEEN ENQUEUED\n", element);
}

void dequeue()	//Function to delete elements from queue
{
    struct node *temp;
    temp=front;
    if(front==NULL)
    {
        printf("\nQUEUE IS EMPTY!\n");
    }
    else
    {
        if(temp->ptr!=NULL)
        {
            int delete_num= temp->num;
            front=front->ptr;
            printf("\n %d HAS BEEN DEQUEUED\n", delete_num);
        }
        else
        {
            printf("\n %d HAS BEEN DEQUEUED\n", front->num);
            front=NULL;
            rear=NULL;
        }
    }
}

void queue_display()	//Function to display elements in queue
{
    struct node *temp;
    temp=front;
    if(front==NULL && rear==NULL)
    {
        printf("\nQUEUE IS EMPTY!\n");
        return;
    }
    printf(" \nELEMENTS IN QUEUE: \n");
    while(temp!=rear)
    {
        printf("%d ", temp->num);
        temp=temp->ptr;
    }
    if(temp==rear)
       printf("%d ", temp->num); 
    printf("\n");
}
