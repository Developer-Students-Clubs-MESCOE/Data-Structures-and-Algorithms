//Program to execute implement mentioned matrix using singly linked list
/*Taniya S. Kulkarni
Roll Number: COE19B046*/

#include<stdio.h>
#include<stdlib.h>

//Node for linked list
struct node
{
    int num;
    int row;
    int col;
    struct node *next;
} *head = NULL, *temp;

//Functions used in program
void insert(int row_val, int col_val, int val);
int create_matrix(int mat_row, int mat_col);
void print(int mat_row, int mat_col);


//Main function
void main()
{
    int rval, cval, choice, mat_row, mat_col, val;
    printf("Enter Number of Rows in matrix: ");
    scanf("%d", &rval);
    printf("Enter Number of Columns in matrix: ");
    scanf("%d", &cval);
    printf("\n -------------------------------\n");
    do{
        printf("\n Enter row in which you wish to insert element: ");
        scanf("%d", &mat_row);
        printf(" Enter column in which you wish to insert element: ");
        scanf("%d", &mat_col);
        printf(" Enter element you wish to insert: ");
        scanf("%d", &val);
        insert(mat_row, mat_col, val);
        printf("\nDo you wish to enter another element? (1/0): ");
        scanf("%d", &choice);
        printf("\n -------------------------------\n");
    }while(choice);
    print(rval, cval);
}

//Function to insert into linked list
void insert(int row_val, int col_val, int val)
{
    struct node *new;
    new = (struct node*) malloc(sizeof(struct node));
    new->num = val;
    new->row = row_val;
    new->col = col_val;
    new->next = NULL;
    if(head == NULL)
    {
        head = new;
        return;
    }
    else
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next = new;
    }
    
}

//Function to display entered element in the given position
int create_matrix(int mat_row, int mat_col)
{
    int exit_out = 0;
    struct node *temp;
    for(temp = head; temp != NULL; temp=temp->next)
    {
        if(temp->col == mat_col && temp->row == mat_row)
        {
            printf(" %d ", temp->num);    
            exit_out= 1;
            break;
        }
    }
    return exit_out;
}

//Funtion to print out the matrix based on the linked list
void print(int mat_row, int mat_col)
{
    printf("\n -------------------------------");
    printf("\n OUTPUT MATRIX: \n\n");
    for(int i=0; i<mat_row; i++)
    {
        for(int j=0; j<mat_col; j++)
        {
            if(create_matrix(i,j) == 0)
            {
                printf(" 0 ");
            }
        }
        printf("\n");
    }
    
}

















