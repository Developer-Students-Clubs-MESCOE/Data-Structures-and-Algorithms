#include<iostream>
using namespace std;

class Queue{
	public :
		int size,Queue[100],i = 0,nice,j;
		int front = -1;
		int rear = -1;
		
		void readQueue(int n)
		{
			size = n;
		}
		
		void enqueue(int element)
		{
				Queue[i] = element;
				i++;
				rear++;	
		}
		
		int Dequeue(){			
			if(front < rear){
			front++;
			return Queue[front];
			}
		}
		
		void display(){
			cout<<"\n";
			if(front == rear){
				cout<<"Queue is empty";
			}
			else{
				for(j = front + 1 ; j <= rear ; j++){
					cout<<Queue[j];
				}
			}
			
		}
		
		int isEmpty(){
			if(front == rear){
				return 1;
			}
			else{
				return 0;
			}
		}
};


class Graph{
	public :
		int size1,i,j,G[100][100,u,v,min=999;;		
		void readGraph(int n){
			for(i = 0 ; i < n ; i++)
			{
				for(j = 0 ; j < n ; j++)
				{
					cin>>G[i][j];
				}
			}
		}
		
		void BFS(int f , int n , Queue Q){
			int path[50],current,i,j=0;
			int visited[n] ={0};
			visited[f] = 1;
			Q.enqueue(f);
			path[j] = f;
			j++;
			
			while(!Q.isEmpty()){
				current = Q.Dequeue();
				for(i = 0 ; i < n ; i++){
					if(G[current][i] == 1 && visited[i] == 0){
						visited[i] = 1;
						Q.enqueue(i);
						path[j] = i;
						j++;
					}
				}
			}
			cout<<"\n";
			cout<<"The BSF path is ->";
			for(i = 0 ; i < j ; i++){
				cout<<"-->"<<path[i];
			}
		}
};


int main()
{
	int n,node;
	Queue Q;
	Graph G;
	cout<<"Enter no of vertices";
	cin>>n;
	G.readGraph(n);
	cout<<"\n";
	cout<<"Enter the node you want to start search from";
	cin>>node;
	G.BFS(node , n ,Q);
}

/*
Enter no of vertices6
0 1 0 0 1 0
1 0 1 1 1 0
0 1 0 1 0 1
0 1 1 0 1 1
1 1 0 1 0 1
0 0 1 1 1 0

Enter the node you want to start search from :- 0

The BSF path is ->-->0-->1-->4-->2-->3-->5
*/
