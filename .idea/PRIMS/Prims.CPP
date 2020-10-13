//Program to create graph
//The graph is represented using adjacency list
//Implements the prim's algorithm

#include<iostream.h>
#include<conio.h>

struct node	//create structure of node
{
	int data;
	int weight;
	node *next;
};

class graph
{
public:
	node *head[20], *p[20];	//for storing head node
	int no, visited[20];
	int count, min_wt;

	void display(int);
	void create_edge(int, int, int, int);
	void prim(int vertex[]);
	void disp(int vertex[]);
};

void graph :: create_edge(int v1, int v2, int w, int mark)
{
	node *n, *f, *h;

	//creating link from v1 to v2
	h = new node;
	h->data = v1;
	h->weight = NULL;
	h->next = NULL;

	n = new node;	//allocate memory for new node
	n->data = v2;	//assign vertex
	n->weight = w;
	n->next = NULL;	//next link will be NULL

	if(mark == 0)
		f = head[v1];	//header vertex of graph
	else
		f = p[v1];	//header vertex of minimum spanning tree

	if(f == NULL)
	{
		h->next = n;
		if(mark == 0)
			head[v1] = h;	//create header vertex of graph
		else
			p[v1] = h;	//create header vertex of minimum spanning tree
	}
	else
	{
		while(f->next)
		      f = f->next;
		f->next = n;
	}

}

void graph :: display(int mark)
{
	int i;
	node *f;
	for(i = 0 ; i < no; i++)
	{
		cout<<endl;
		if(mark == 0)
			f = head[i];	//header vertex for graph
		else
			f = p[i];	//header vertex for prim algo
		while(f)
		{
			cout<<"\t"<<f->data;
			f = f->next;
		}
	}
}

void graph :: prim(int vertex[])
{
	node *n;
	int m, v, v1, v2;
	int set_v1[10], set_v2[10], set_wt[10];
	int i,j;

	//Initialization
	for(i = 0; i<10; i++)
	{
		set_v1[i] = -1;
		set_v2[i] = -1;
		set_wt[i] = -1;
	}

	j = 0;
	for(i = 0; i<=count; i++)
	{
		v = vertex[i];	//get element from set of vertex
		n = head[v];	//get header node
		n = n->next;

		while(n)	//if n != NULL
		{
			//make a set of unvisited edges(v1, v2)
			if(visited[n->data] == 0)
			{
				set_v1[j] = v;
				set_v2[j] = n->data;
				set_wt[j] = n->weight;
				j++;
			}
			n = n->next;
		}
	}

	m = set_wt[0];
	v1 = set_v1[0];
	v2 = set_v2[0];

	//find the minimum edge(v1, v2) from unvisited edges
	for(i = 0; i<j; i++)
	{
		if(m > set_wt[i])
		{
			m = set_wt[i];
			v1 = set_v1[i];
			v2 = set_v2[i];
		}
	}

	min_wt += m;	//total minimum cost

	if(visited[v2] == 0)
	{
		visited[v2] = 1;	//mark vertex as visited
		vertex[++count] = v2; 	//set of vertex having minimum weight
		create_edge(v1, v2, 0, 1);	//create adj list of prim algo
		create_edge(v2, v1, 0, 1);	//create adj list of prim algo
	}
	cout<<"\n Set of visited vertex v :";
	if(count < no-1)
	{
		disp(vertex);
		prim(vertex);
	}
	else
		disp(vertex);

}
void graph :: disp(int vertex[])
{
	for(int i = 0; i<=count; i++)
	{
		cout<<" "<<vertex[i];
	}
	cout<<endl;
}

void main()
{
	graph g;
	g.count = 0;
	g.min_wt = 0;
	int v1, v2, w;
	int i, v, edge;
	int vertex[20];

	clrscr();

	cout<<"\n Enter the number of vertice in graph :";
	cin>>g.no;

	//Initialization of graph
	for(i = 0; i<g.no; i++)
	{
		g.head[i] = NULL;
		g.p[i] = NULL;
		g.visited[i] = 0;
	}

	cout<<"\n\n Enter the number of egdes : ";
	cin>>edge;

	for(i = 0; i<edge; i++)
	{
		cout<<"\n Enter edge with weight(V1, V2, Weight)";
		cin>>v1>>v2>>w;

		g.create_edge(v1, v2, w, 0);
		g.create_edge(v2, v1, w, 0);
	}

	cout<<"\n\n The adjacency list of the graph is \n";
	g.display(0);

	cout<<"\n\n Enter the starting vertex :";
	cin>>v;

	vertex[g.count] = v;
	g.visited[v] = 1;	//mark vertex as visited

	cout<<endl;

	g.prim(vertex);	//call prim's algo

	cout<<"\n\n Adjacency list of Minimum spanning tree is "<<endl;
	g.display(1);

	cout<<"\n\n Minimum weight = "<<g.min_wt;

	getch();

}