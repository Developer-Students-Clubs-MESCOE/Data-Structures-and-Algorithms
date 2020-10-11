//Header file with character and integer stack
//Author: Taniya Kulkarni

#include <stdio.h>
#define size 10


/*INTEGER*/


//Integer structure
struct int_stack
{
	int top;
	int arr[size];
	void (*int_push)(int,struct int_stack*);
	void (*int_display)(struct int_stack*);
	void (*int_pop)(struct int_stack*);
};

/*Integer Stack functions*/

//Funtion to push integer values into the stack
void int_push(int num,struct int_stack *sta) 
{
     if(sta->top == size-1) //Checking if the stack has reached its maximum capacity
    {
        printf(" Stack Overflow\n");
    }
    else
    {
        sta->top=sta->top + 1;
        sta->arr[sta->top]=num; //Assigning the number entered by the user to the top of the stack
        printf(" %d has been pushed! \n", num);
    }
}

//Funtion to display integer values in the stack
void int_display(struct int_stack *sta)
{
    if(sta->top==-1)    //Checking if the stack is empty
    {
        printf(" The stack is empty\n");
    }
    else
    {
        printf("\n Stack:\n");
        for(int i=sta->top; i>-1;i--)   //Printing all the elements in stack from top to bottom
        {
            printf("%d ",sta->arr[i]);
        }
	    printf("\n");   
    }
}

//Funtion to pop integer values in the stack
void int_pop(struct int_stack *sta)
{
    if(sta->top<0)    //Checking if the stack is empty
    {
        printf(" Stack is empty!\n");
    }
    else
    {
        int item= sta->arr[sta->top];
        sta->top=sta->top-1;
        printf(" Element has been popped!\n");
    }
}


/*CHARACTER*/

//Character Structure
struct char_stack
{
    int top;
    char arr[size];
    void (*char_push)(char,struct char_stack*);
    void (*char_display)(struct char_stack*);
    void (*char_pop)(struct char_stack*);
};

/*Character Stack Functions*/

//Funtion to push characters into the stack
void char_push(char character,struct char_stack *sta)
{
     if(sta->top == size-1) //Checking if the stack has reached its maximum capacity
    {
        printf(" Stack Overflow\n");
    }
    else
    {
        sta->top=sta->top + 1;
        sta->arr[sta->top]=character;   //Assigning the character entered by the user to the top of the stack
    }
}

//Funtion to display the characters in the stack
void char_display(struct char_stack *sta)
{
    if(sta->top==-1)     //Checking if the stack is empty
    {
        printf(" The stack is empty\n");
    }
    else
    {
        printf("\n Stack:\n");
        for(int i=sta->top; i>-1;i--)
        {
            printf("%c ",sta->arr[i]);  //Printing all the elements in stack from top to bottom
        }
	    printf("\n");   
    }
}

//Funtion to pop characters in the stack
void char_pop(struct char_stack *sta)
{
    if(sta->top<0)   //Checking if the stack is empty
    {
        printf(" Stack is empty!\n");
    }
    else
    {
        char item= sta->arr[sta->top];
        sta->top=sta->top-1;
    }
}





