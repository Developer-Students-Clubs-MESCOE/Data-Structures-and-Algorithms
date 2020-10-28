#include<stdio.h>
int main()
{
	int n,i,j,m=2,cost=0;
	printf("Enter no of vertices you need");
	scanf("%d",&n);
	printf("\n");
	printf("Enter 9999 if no edge exist");
	printf("\n");
	int G[n][n];
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			scanf("%d",&G[i][j]);
		}
	}
	
	int u,v,min=999;
	for(i = 0 ; i < n ; i++)
	{
		for(j = i ; j < n ; j++)
		{
			if(G[i][j] < min)
			{
				min = G[i][j];
				u = i;
				v = j;
			}
		}
	}
	
	cost = cost + G[u][v];
	
	 int visited[n] = {0};	
	int value[100];
	value[0] = u;
	value[1] = v;
	visited[u] = 1;
	visited[v] = 1;
	printf("\n");
 	 	
 for(int z = 1 ; z <= n-2 ; z++)
 {	
 	min = 999;
	for(i = 0 ; i < n ; i++)
	{
		for(j = 0 ; j < n ; j++)
		{
			if(visited[i] != 1 && visited[j] == 1)
			{
				if(G[i][j] < min)
				{
					min = G[i][j];
					u = j;
					v = i;
				}
			}
		}
	}
	visited[u] = 1;
	visited[v] = 1;
	value[m] = u;
	m++;
	value[m] = v;
	m++;
	cost = cost + G[u][v];
 }
 
 printf("Prims way is : -");
 printf("\n");  
 	printf("\n");
 	int t=1;
 	for(i = 0 ; i < m ; i++)
 	{
 		printf("%d --> ",value[i]);
 		if(t >= 2)
 		{
 			printf("\n");
 			t = 0;
		 }
		 t++;
	 }
	 
	 printf("\n");
	 
	 printf("Minimum cost of the spnning tree is :- %d",cost);

}
