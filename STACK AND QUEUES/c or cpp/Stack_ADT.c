//Program to implement stack ADT using singly linked list
//Author: Taniya Kulkarni

#include <stdio.h>
#include "COE19B046_list.h"

void main()
{
    int choice;
    create_stack();
    do{
        printf("\nChoose what operation you wish to do: \n 1. Push \n 2. Display \n 3. Pop \n 0. Exit \n Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: 	//Option to Push elements into stack
            {
                int element;
                printf("\nEnter number you wish to push:");
                scanf("%d", &element);
                push(element);
                break;
            }
            case 2:	//Option to Display elements in stack
            {
                stack_display();
                break;
            }
            case 3:	//Option to Pop elements from stack
            {
                pop();
                break;
            }
            default:
            {
                if(choice!=0)
                {
                    printf("\n Wrong Choice!!\n");
                }
            }
            
        }
    }while(choice!=0);
}
