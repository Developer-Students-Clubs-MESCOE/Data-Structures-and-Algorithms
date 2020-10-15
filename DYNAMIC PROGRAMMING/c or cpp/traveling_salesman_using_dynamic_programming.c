#include<stdio.h> 
int a[10][10],completed[10],n,cost=0;
void mincost(int city); 
int minValue(int c);
int main()
{
	int i,j;
	printf("Enter the number of villages: ");
	scanf("%d",&n);
	printf("\nEnter the Cost Matrix (%dX%d):\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
		completed[i]=0;
	}
	printf("\n\nThe cost list is:\n");
	for( i=0;i < n;i++)
	{
		for(j=0;j < n;j++)
		{
			printf("\t%d",a[i][j]);
		}
		printf("\n");
	}
	printf("\nThe Path for travelling salesman is:\n");
	mincost(0);
	printf("\nMinimum cost is:%d\n",cost);
	return 0;
}
void mincost(int city)
{
	int i,nextCity;
	completed[city]=1;
	printf("%d:",city+1);
	nextCity=minValue(city);
	if(nextCity==999)
	{
		nextCity=0;
		printf("%d",nextCity+1);
		cost+=a[city][nextCity];
		return;
	}
	mincost(nextCity);
}
 
int minValue(int c)
{
	int i,nc=999;
	int min=999,min1;
	for(i=0;i < n;i++)
	{
		if((a[c][i]!=0)&&(completed[i]==0))
		{
			if(a[c][i]+a[i][c] < min)
			{
				min=a[i][0]+a[c][i];
				min1=a[c][i];
				nc=i;
			}
		}
	}
	if(min!=999)
	{
		cost+=min1;
	}
	return nc;
}


/*
OUTPUT:
Enter the number of villages: 4

Enter the Cost Matrix (4X4):
0 10 5 4
10 0 2 3
5 2 0 1
4 3 1 0


The cost list is:
	0	10	5	4
	10	0	2	3
	5	2	0	1
	4	3	1	0

The Path for travelling salesman is:
1:4:3:2:1
Minimum cost is:17 */
