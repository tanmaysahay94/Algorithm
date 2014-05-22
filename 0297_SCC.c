#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int destination;
	struct node *link;
}node;
typedef struct fin
{
	int destination,time;
}fin;
int cmp(const void *a,const void *b)
{
	return (*(fin *)a).time-(*(fin *)b).time;
}
int visited[550],finishCount,time;
fin finish[550];
node *newNode(int destination)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->destination=destination;
	temp->link=NULL;
	return temp;
}
node *append(node *linkedList,node *vertex)
{
	if(!linkedList)
		return vertex;
	node *temp;
	temp=linkedList;
	while(temp->link)
		temp=temp->link;
	temp->link=vertex;
	return linkedList;
}
void dfs(node *graph[],int start)
{
	node *next;
	if(!visited[start])
	{
		visited[start]=1;
		next=graph[start];
		while(next)
		{
			if(visited[next->destination])
				next=next->link;
			else if(next)
			{
				time++;
				dfs(graph,next->destination);
			}
		}
	}
	time++;
	finish[finishCount].destination=start;
	finish[finishCount].time=time;
	finishCount++;
}
int main()
{
	int t,v,e,v1,v2,i,j,count;
	node *temp,*dirGraph[550],*dirT[550],*del;
	scanf("%d",&t);
	while(t--)
	{
		finishCount=count=time=0;
		scanf("%d%d",&v,&e);
		for(i=0;i<v;i++)
			finish[i].time=finish[i].destination=visited[i]=0;
		for(i=0;i<550;i++)
			dirGraph[i]=dirT[i]=NULL;
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&v1,&v2);
			dirGraph[v1]=append(dirGraph[v1],newNode(v2));
			dirT[v2]=append(dirT[v2],newNode(v1));
		}
		for(i=0;i<v;i++)
			if(!visited[i])
				dfs(dirGraph,i);
		for(i=0;i<v;i++)
			visited[i]=0;
		qsort(finish,v,sizeof(fin),cmp);
		for(i=v-1;i>=0;i--)
			if(!visited[finish[i].destination])
			{
				dfs(dirT,finish[i].destination);
				count++;
			}
		printf("%d\n",count);
		for(i=0;i<v;i++)
		{
			temp=dirGraph[i];
			while(temp)
			{
				del=temp;
				temp=temp->link;
				free(del);
			}
		}
		for(i=0;i<v;i++)
		{
			temp=dirT[i];
			while(temp)
			{
				del=temp;
				temp=temp->link;
				free(del);
			}
		}
	}
	return 0;
}
