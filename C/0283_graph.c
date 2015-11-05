#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define NOT_VISITED 0
#define IN_PROGRESS 1
#define VISITED 2
typedef struct node
{
	int vertex,parent,state;
}node;
int graph[1001][1001];
int last_vertex=0;
void add(int u,int v)
{
	int max;
	graph[u][v]=graph[v][u]=1;
	max=u>v?u:v;
	last_vertex=last_vertex>max?last_vertex:max;
}
void rem(int u,int v)
{
	int i,j,maxBwUv;
	graph[u][v]=graph[v][u]=0;
	maxBwUv=u>v?u:v;
	if(last_vertex==maxBwUv)
		for(i=last_vertex;i>=1;i--)
			for(j=last_vertex;j>=1;j--)
				if(graph[i][j])
					last_vertex=i>j?i:j;
}
void bfs(int start)
{
	node vertex_list[1001],queue[1001];
	int i,j,head,tail;
	for(i=1;i<=last_vertex;i++)
		for(j=1;j<=last_vertex;j++)
			if(graph[i][j])
			{
				vertex_list[i].vertex=i;
				vertex_list[i].state=NOT_VISITED;
				break;
			}
	head=tail=0;
	if(!head)
	{
	}
}
int main()
{
	int i,j,choice,continueOrNot,garbage,u,v,start;
	for(i=0;i<1001;i++)
		for(j=0;j<1001;j++)
			graph[i][j]=0;
	do
	{
		printf("1. Add an edge (u,v)\n2. Remove an edge (u,v)\n3.Print BFS\nExit with any other character\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Vertices are 1-indexed and max value of v is 1000\n");
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		else if(choice==2)
		{
			printf("Vertices are 1-indexed and max value of v is 1000\n");
			scanf("%d%d",&u,&v);
			rem(u,v);
		}
		else if(choice==3)
		{
			scanf("%d",&start);
			bfs(start);
		}
		else
			return 0;
		printf("Press y to continue\n");
		scanf("%c%c",&garbage,&continueOrNot);
	}while(continueOrNot=='y'||continueOrNot=='Y');
}
