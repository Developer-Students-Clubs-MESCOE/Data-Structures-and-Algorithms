//Program to see the different kind of sorts
//Author: Taniya Kulkarni
#include <stdio.h>

void bubblesort(int arr[], int n)		//Function that sorts using bubble sort mechanism
{
	int temp;
    	for(int i=1;i<n;i++)
    	{
		for(int j=0;j<n-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
			   temp=arr[j];		//Swaaping of elements
			   arr[j]=arr[j+1];
			   arr[j+1]=temp;
			}
		}
      
		for(int k=0;k<n;k++)		//To print the array after every pass
		{
			printf("%d ", arr[k]);
		}
		printf("\n");
    	}
	printf("Sorted Array: \n");		//To print the final sorted array
	for(int i=0;i<n;i++)
	{
	   printf("%d ", arr[i]);
	}
	printf("\n");
}

void insertionsort(int arr[], int n)		//Function that sorts using insertion sort mechanism
{
	int temp,j;
	for(int i=1;i<n;i++)
    	{
		temp=arr[i];
		j=i-1;
		while((temp<arr[j])&&(j>=0))
		{
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=temp;
		for(int k=0;k<n;k++)		//To print the array after every pass
		{
		  printf("%d ", arr[k]);
		}
		printf("\n");
    	}	
    	printf("Sorted Array: \n");		//To print the final sorted array
    	for(int i=0;i<n;i++)
    	{
       		printf("%d ", arr[i]);
    	}
	printf("\n");
}


void selectionsort(int arr[], int n)		//Function that sorts using selection sort mechanism
{
    	int temp;
    	for(int i=0;i<n;i++)
    	{
       		for(int j=i+1;j<n;j++)
        	{
            		if(arr[i]>arr[j])
            		{
                		temp=arr[i];		//Swapping of elements
                		arr[i]=arr[j];
                		arr[j]=temp;
            		}
        	}
        	for(int k=0;k<n;k++)		//To print the array after every pass	
        	{
            		printf("%d ", arr[k]);
        	}
        	printf("\n");
   	}
    	printf("Sorted Array: ");		//To print the final sorted array
    	for(int i=0;i<n;i++)
    	{
        	printf("%d ", arr[i]);
    	}
	printf("\n");
}

void main()
{
	int n, option,flag;
	printf("Enter size of array: ");
	scanf("%d", &n);
	do
	{
		if(n>5)
		{
			int arr[n];
			printf("\nEnter numbers into array:\n");	//To enter values into array
			for(int i=0; i<n; i++)
			{
				scanf("%d", &arr[i]);  
			}
			printf("Choose which method you wish to sort the array with: \n1. Bubble Sort \n2. Selection sort \n3. Insertion Sort");
			printf("\n Enter option: ");
			scanf("%d", &option);
			switch(option)
			{
				case 1:		//Option 1, i.e, to sort a given array using bubble sort
				{
					printf("You've chosen Bubble Sort!\n");
					bubblesort(arr,n);
					flag=0;
					break;
				}
				case 2:		//Option 2, i.e, to sort a given array using Selection sort
				{
					printf("You've chosen Selection Sort!\n");
					selectionsort(arr,n);
					flag=0;
					break;
				}
				case 3:		//Option 3, i.e, to sort a given array using Insertion sort
				{
					printf("You've chosen Insertion Sort!\n");
					insertionsort(arr,n);
					flag=0;
					break;
				}
				default:
				{
					printf("Wrong choice!!");
					flag=1;
				}
			}
		}
		
		else		//If the size entered is less than or equal to 5
		{
			printf("\nNumber of entries should be more than five \n Try again!\n");
			flag=1;
			printf("\nEnter size of array: ");
			scanf("%d", &n);
		}
	}while(flag);
}