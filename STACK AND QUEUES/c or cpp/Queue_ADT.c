//Program to implement queue ADT using singly linked list
//Author: Taniya Kulkarni

#include <stdio.h>
#include "COE19B046_list.h"


void main()
{
    int choice;
    create_queue();
    do{
        printf("\nChoose what operation you wish to do: \n 1. Enqueue \n 2. Display \n 3. Dequeue \n 0. Exit \n Enter choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:	//Option to Enqueue
            {
                int element;
                printf("\nEnter number you wish to enqueue:");
                scanf("%d", &element);
                enqueue(element);
                break;
            }
            case 2:	//Option to display elements in queue
            {
                queue_display();
                break;
            }
            case 3:	//Option to Dequeue
            {
                dequeue();
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
