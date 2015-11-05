#include<stdio.h>
#include<stdlib.h>
typedef struct qNode
{
	int node;
	struct qNode *link;
}qNode;
int visitedVertex[1000];
qNode *newNode(int d)
{
	qNode *temp=(qNode *)malloc(sizeof(qNode));
	temp->node=d;
	temp->link=NULL;
	return temp;
}
int bfs(int adj[][1000],int start,int numberOfNodes)
{
	qNode *head,*tail,*toQueue;
	head=tail=NULL;
	int i,count=0,recentlyRemoved;
	toQueue=newNode(start);
	head=tail=toQueue;
	visitedVertex[start]=1;
	while(head!=NULL)
	{
		if(head==tail)
		{
			recentlyRemoved=head->node;
			tail=head=head->link;
		}
		else
		{
			recentlyRemoved=head->node;
			head=head->link;
		}
		count++;
		for(i=0;i<numberOfNodes;i++)
			if(adj[recentlyRemoved][i])
				if(!visitedVertex[i])
				{
					toQueue=newNode(i);
					visitedVertex[i]=1;
					if(head==NULL&&tail==NULL)
						head=tail=toQueue;
					else
					{
						tail->link=toQueue;
						tail=tail->link;
					}
				}
	}
	return count;
}
int main()
{
	int max,t,i,j,n,adjacency[1000][1000],visitedVertexCount,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				scanf("%d",&adjacency[i][j]);
		for(i=0;i<n;i++)
			visitedVertex[i]=0;
		visitedVertexCount=max=0;
		while(visitedVertexCount<n-1)
			for(i=0;i<n;i++)
				if(!visitedVertex[i])
				{
					visitedVertexCount+=(k=bfs(adjacency,i,n));
					max=max>k?max:k;
					visitedVertex[i]=1;
					break;
				}
		printf("%d\n",max);
	}
	return 0;
}
