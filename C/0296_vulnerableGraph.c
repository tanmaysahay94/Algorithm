#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int destination;
	struct node *link;
}node;
int inOrNot[1100],visited[1100],low[1100],num[1100],ap[1100],parent[1100],apCount[1100],vul[1100],vulCount;
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
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
void findArt(node *g[],int v)
{
	static int time=0;
	node *w;
	visited[v]=1;
	low[v]=num[v]=++time;
	w=g[v];
	while(w)
	{
		if(!visited[w->destination])
		{
			parent[w->destination]=v;
			findArt(g,w->destination);
			if(low[w->destination]>=num[v]&&!inOrNot[v])
			{
				inOrNot[v]=1;
				vul[vulCount++]=v;
			}
			low[v]=min(low[v],low[w->destination]);
		}
		else if(parent[v]!=w->destination)
			low[v]=min(low[v],num[w->destination]);
		w=w->link;
	}
}
int main()
{
	int t,v,e,v1,v2,i;
	node *graph[1100],*temp,*del;
	scanf("%d",&t);
	while(t--)
	{
		vulCount=0;
		scanf("%d%d",&v,&e);
		for(i=0;i<1100;i++)
		{
			inOrNot[i]=0;
			low[i]=-1;
			num[i]=-1;
			visited[i]=0;
			parent[i]=-1;
			graph[i]=NULL;
		}
		for(i=0;i<e;i++)
		{
			scanf("%d%d",&v1,&v2);
			graph[v1]=append(graph[v1],newNode(v2));
			graph[v2]=append(graph[v2],newNode(v1));
		}
		findArt(graph,0);
		if(vulCount==1)
			printf("NONE\n");
		else
		{
			qsort(vul,vulCount,sizeof(int),cmp);
			for(i=1;i<vulCount-1;i++)
				printf("%d ",vul[i]);
			printf("%d\n",vul[i]);
		}
		for(i=0;i<v;i++)
		{
			temp=graph[i];
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
