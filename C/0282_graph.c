#include<stdio.h>
#include<stdlib.h>
#define MAX 20
typedef enum boolean{false,true} bool;
int adj[MAX][MAX];
bool visited[MAX];
int n;    //number of nodes in the graph
void create_graph()
{
	int i,max_edges,origin,destin;
	printf("Enter number of nodes : ");
	scanf("%d",&n);
	max_edges=n*(n-1);
	for(i=1;i<=max_edges;i++)
	{
		printf("Enter edge %d (0 0 to quit): ",i);
		scanf("%d%d",&origin,&destin);
		if((origin==0) && (destin==0))
			break;
		if( origin > n || destin > n || origin<=0 || destin<=0)
		{
			printf("Invalid edge!\n");
			i--;
		}
		else
			adj[origin][destin]=1;
	}
}
void display()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			printf("%4d",adj[i][j]);
		printf("\n");
	}
}
void bfs(int v)
{
	int i,front,rear;
	int que[20];
	front=rear= -1;
	printf("%d ",v);
	visited[v]=true;
	rear++;
	front++;
	que[rear]=v;
	while(front<=rear)
	{
		v=que[front];     //deque
		front++;
		for(i=1;i<=n;i++)
		{
			//check for unvisistd nodes
			if( adj[v][i]==1 && visited[i]==false)
			{
				printf("%d ",i);
				visited[i]=true;
				rear++;
				que[rear]=i;
			}
		}
	}
}
int main()
{
	int i,v,choice;
	create_graph();
	while(1)
	{
		printf("\n");
		printf("1. Adjacency matrix\n");
		printf("2. Breadth First Search\n");
		printf("3. Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Adjacency Matrix\n");
				display();
				break;
			case 2:
				printf("Enter starting node for Breadth First Search : ");
				scanf("%d", &v);
				for(i=1;i<=n;i++)
					visited[i]=false;
				bfs(v);
				break;
			case 3:
				exit(1);
			default:
				printf("Wrong choice\n");
				break;
		}
	}
	return 0;
}
