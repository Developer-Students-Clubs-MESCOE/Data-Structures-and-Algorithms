#include<stdio.h>
#include<stdlib.h>
struct edge
{
	int u,v,cost;
};
struct graph
{
	int t_edges,t_vertices;
};
void bellman(struct graph a,struct edge e[],int src);
int w(int u,int v);
void relax(int u,int v);
struct graph a;
struct edge e[30];
int d[10][3];
int main()
{
	int src;
	printf("Enter the number of edges:");
	scanf("%d",&a.t_edges);
	printf("Enter the number of vertices:");
	scanf("%d",&a.t_vertices);
	printf("Let the vetices be:\n");
	for(int i=1;i<=a.t_vertices;i++)
	{
		printf("%d\t",i);
	}
	printf("\n");
	for(int j=0;j<a.t_edges;j++)
	{	
		printf("Enter first vertex of edge %d:",j+1);
		scanf("%d",&e[j].u);
		printf("Enter second vertex of edge %d:",j+1);
		scanf("%d",&e[j].v);
		printf("Enter cost vertex of edge %d:",j+1);
		scanf("%d",&e[j].cost);
	}
	printf("Enter the source vertex:");
	scanf("%d",&src);
	bellman(a,e,src);
}
void bellman(struct graph a,struct edge e[],int src)
{
	for(int j=0;j<a.t_edges;j++)
	{	
		printf("Edge:%d\tu:%d\tv:%d\tcost:%d\n",j,e[j].u,e[j].v,e[j].cost);
	}
	for(int j=0;j<a.t_vertices;j++)
	{
		d[j][0]=j+1;
		d[j][1]=0;
		d[j][2]=0;
	}
	for(int i=0;i<a.t_vertices;i++)
	{
		for(int k=0;k<a.t_edges;k++)
		{
			relax(e[k].u,e[k].v);
		}
	}
	for(int i=0;i<a.t_vertices;i++)
	{
		printf("vertex:%d\tcost:%d\tparent:%d\n",d[i][0],d[i][1],d[i][2]);
	}
	
}
int w(int u,int v)
{
	for(int j=0;j<a.t_edges;j++)
	{	
		if(e[j].u==u && e[j].v==v)
		{
			return e[j].cost;
		}
	}
}
void relax(int u,int v)
{
	if(d[v-1][1]==0 || (d[v-1][1]>(d[u-1][1]+w(u,v))))
	{
		d[v-1][2]=u;
		d[v-1][1]=d[u-1][1]+w(u,v);
	}
}
/*OUTPUT:
Enter the number of edges:5
Enter the number of vertices:4
Let the vetices be:
1	2	3	4	
Enter first vertex of edge 1:1
Enter second vertex of edge 1:2
Enter cost vertex of edge 1:11
Enter first vertex of edge 2:1
Enter second vertex of edge 2:3
Enter cost vertex of edge 2:10
Enter first vertex of edge 3:3
Enter second vertex of edge 3:2
Enter cost vertex of edge 3:12
Enter first vertex of edge 4:2
Enter second vertex of edge 4:4
Enter cost vertex of edge 4:5
Enter first vertex of edge 5:3
Enter second vertex of edge 5:4
Enter cost vertex of edge 5:20
Enter the source vertex:1
Edge:0	u:1	v:2	cost:11
Edge:1	u:1	v:3	cost:10
Edge:2	u:3	v:2	cost:12
Edge:3	u:2	v:4	cost:5
Edge:4	u:3	v:4	cost:20
vertex:1	cost:0	parent:0
vertex:2	cost:11	parent:1
vertex:3	cost:10	parent:1
vertex:4	cost:16	parent:2
*/






