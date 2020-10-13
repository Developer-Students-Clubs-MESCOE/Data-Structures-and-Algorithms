#define infinity 9999
#define MAX 20
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include <limits.h>

using namespace std;

class graph
{ 
public:	
	int G[MAX][MAX];
	string city[MAX];	
  	int n,i;
  
      graph()
	{ 
		n=0; 	
		for(i=0; i<MAX; i++)
			city[i]="";
	}
      	void readgraph();
      	void dijkstra(int graph[MAX][MAX], int src);
	int minDistance(int dist[], bool sptSet[]);
	int printSolution(int dist[], int n);
};

void graph:: readgraph()
{
	int i,j,vi,vj,no_of_edges,weight;
	int flag1, flag2;
	string city1, city2;
	cout<<"\nEnter no. of cities/vertices :";
	cin>>n;
	cout<<"\nEnter no of connectivities/edges :";
	cin>>no_of_edges;
	for(i=0;i<n;i++) //Initialize the adjacency matrix
		for(j=0;j<n;j++)
			G[i][j]=0;
	cout<<"\nEnter the list of edges : ";
	for(i=0;i<no_of_edges;i++)
	{
		cout<<"\nEnter the connectivity between cities (city1,city2,cost)  :";
		cin>>city1>>city2>>weight;
		j=0;
		flag1 = 1; 
		flag2 = 1;
		while(city[j]!="")
		{
			flag1 = 0; 
			if(city[j].compare(city1)==0)
			{
				vi=j;
				j++;
				break;
			}
			else 
				flag1 = 1;
			j++;
		}
		if(flag1 == 1)
		{
			city[j]=city1;
			vi = j;
			j++;
		}
		while(city[j]!="")
		{
			flag2 = 0;
			if(city[j].compare(city2)==0)
			{
				vj=j;
				j++;
				break;
			}
			else
				flag2 = 1;
			j++;
		}
		if(flag2 == 1)
		{
			city[j]=city2;
			vj = j;
			j++;
		}
		G[vi][vj]=G[vj][vi]=weight;
	}
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void graph :: dijkstra(int graph[MAX][MAX], int src)
{
     int dist[n];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[n]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (int count = 0; count < n-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (int v = 0; v < n; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, n);
}

int graph :: minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;
  
   for (int v = 0; v < n; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}

// A utility function to print the constructed distance array
int graph :: printSolution(int dist[], int n)
{
   cout<<"\nCity   			Distance from Source"<<city[0]<<endl;
   for (int i = 0; i < n; i++)
      cout<<"\n"<< city[i] <<" 		"<< dist[i];
}

int main()
{
	graph g1,spanning;
	g1.readgraph();
	g1.dijkstra(g1.G, 0);
	return 0;
}


