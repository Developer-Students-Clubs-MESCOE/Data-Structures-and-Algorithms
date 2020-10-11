#include<stdio.h>
#include<stdlib.h>
#include "dll.h"
//Author: Taniya Kulkarni



void main()
{
    int choice;
    struct node *head = NULL;
    do{
        int item;
        printf("\n ENTER NUMBER INTO LIST: ");
        scanf("%d", &item);
        insert_end (item, &head);
        printf("\n DO YOU WISH TO ENTER ANOTHER NUMBER INTO THE LIST? (Any number/0): ");
        scanf("%d", &choice);
    }while(choice);
    printf("\n----------------------------");
    printf("\nOLD LIST (WITH DUPLICATES): \n");
    display(head);
    printf("\n----------------------------");
    printf("\nNEW LIST (WITHOUT DUPLICATES): \n");
    duplicates(&head);
    display(head);
    printf("\n");
}