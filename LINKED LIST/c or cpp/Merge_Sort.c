#include<stdio.h>
#include<stdlib.h>
#include "dll.h"
//Author: Taniya Kulkarni

struct node *list3=NULL;

void sort (struct node *head)
{
	isempty(head);
	if( head != NULL )
	{
		int flag, swap;
		struct node *sorted = NULL;
		do
		{
			flag = 0;
			ptr = head;
			while (ptr->next != sorted)
			{
				if(ptr->num > ptr->next->num)
				{
					swap = ptr->num;
					ptr->num = ptr->next->num;
					ptr->next->num = swap;
					flag = 1;
				}
				ptr = ptr->next;
			}
			sorted = ptr;
		}while (flag);
	}
}

void merge(struct node *head1, struct node *head2)
{
    isempty(head1);
    isempty(head2);
    if(head1 != NULL && head2 != NULL)
    {
        struct node *temp1 = head1;
        struct node *temp2 = head2;
        while(temp1 != NULL)
        {
            insert_end(temp1->num, &list3);
            temp1 = temp1->next;
        }
        while(temp2 != NULL)
        {
            insert_end(temp2->num, &list3);
            temp2 = temp2->next;
        }
    }
    sort(list3);
}

void main()
{
    int choice1, choice2;
    struct node *head1 = NULL;
    struct node *head2 = NULL;
    printf ("\nLIST 1:");
    printf("\n --------------------------\n");
    do{
        int item;
        printf("\n ENTER NUMBER INTO LIST 1: ");
        scanf("%d", &item);
        insert_end (item, &head1);
        printf("\n DO YOU WISH TO ENTER ANOTHER NUMBER INTO THE LIST? (Any number/0): ");
        scanf("%d", &choice1);
    }while(choice1);
    printf ("\nLIST 2:");
    printf("\n --------------------------\n");
    do{
        int item;
        printf("\n ENTER NUMBER INTO LIST 2: ");
        scanf("%d", &item);
        insert_end (item, &head2);
        printf("\n DO YOU WISH TO ENTER ANOTHER NUMBER INTO THE LIST? (Any number/0): ");
        scanf("%d", &choice2);
    }while(choice2);
    printf("\n----------------------------");
    printf("\nLIST 1: \n");
    display(head1);
    printf("\n----------------------------");
    printf("\n----------------------------");
    printf("\nLIST 2: \n");
    display(head2);
    printf("\n----------------------------");
    printf("\n----------------------------");
    printf("\n LIST 3: \n");
    merge(head1, head2);
    display(list3);
    printf("\n----------------------------\n");
}