//Program to convert Infix to Postfix
//Author: Taniya Kulkarni

#include <string.h>
#include <ctype.h>
#include "stack.h"

//Funtion required to convert infix to postfix
int precedence(char character); 
void infix_to_postfix(char expression[]);

//Main function
void main()
{
    char expression[100];
    printf("Enter your infix expression: ");
    scanf(" %s", expression);
    infix_to_postfix(expression);
}

//Function to check precedence of the operator
int precedence(char character)
{
    	if(character=='^')	//Highest precedence
        	return 3;

    	if(character == '*' || character == '/')
		return 2;

	else if(character == '+' || character == '-')    //Lowest Precedence      
		return 1;

	else
		return 0;
}

//Funtion to convert infix to postfix
void infix_to_postfix(char expression[])
{
    int i;
    struct char_stack stk;
    stk.char_push = char_push;
    stk.char_pop = char_pop;
    stk.char_display = char_display;
    stk.top = -1;
    strncat(expression,"$",2);
    printf("\nThe expression in postfix is:\n");
    for (i=0; expression[i]!='$'; i++)
    {
        if (isalpha(expression[i]))
            printf(" %c",expression[i]);
        
        else if (expression[i] == '(')
            stk.char_push(expression[i], &stk);
            
        else if (expression[i] == ')')
        {
            while( stk.arr[stk.top] != '(')
            {   
                printf(" %c", stk.arr[stk.top]);
                stk.char_pop(&stk);
            }
            stk.char_pop(&stk);
        }
        
        else
        {
            while(precedence(stk.arr[stk.top]) >= precedence(expression[i]))
            {
                printf(" %c", stk.arr[stk.top]);
                stk.char_pop(&stk);
            }
            stk.char_push(expression[i], &stk);
        }    
    }
    
    while(stk.top != -1)
    {
        printf(" %c", stk.arr[stk.top]);
        stk.char_pop(&stk);
    }
    printf("\n");

}