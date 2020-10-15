#include<stdio.h>
#include<stdlib.h>
int min,max;
int arr[10];
void minmax(int i,int j);
int main()
{
	int n;
	printf("\nEnter the number of elements:");
	scanf("%d",&n);
	printf("\nEnter the elements of the array:\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	min=arr[0];
	max=arr[0];
	minmax(0,n-1);
	printf("\nThe min element is:%d \nThe max element is:%d \n",min,max);
}

void minmax(int i,int j)
{
	int mid,mintemp,maxtemp;
	if(i==j)
	{
		min=arr[i];
		max=arr[i];
	}
	else
	{
		if(i==(j-1))
		{
			if(arr[i]<arr[j])
			{
				max=arr[j];
				min=arr[i];
			}
			else
			{
				min=arr[j];
				max=arr[i];
			}
		}
		else
		{
			mid=(i+j)/2;
			minmax(i,mid);
			maxtemp=max; 
			mintemp=min;
			minmax(mid+1,j);
			if(max<maxtemp)
			{
				max=maxtemp;
			}
			if(min>mintemp)
			{
				min=mintemp;
			}
		}
	}
}
/*OUTPUT:

Enter the number of elements:5

Enter the elements of the array:
12
23
1
78
35

The min element is:1 
The max element is:78 
*/




























