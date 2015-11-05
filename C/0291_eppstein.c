#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int destination,weight,frequency;
	struct node *link;
}node;
typedef struct mh
{
	int location,weight;
}mh;
int visited[5500],minCount;
mh min[300000];
node *newNode(int dest,int weight)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->destination=dest;
	temp->weight=weight;
	temp->frequency=0;
	temp->link=NULL;
	return temp;
}
node *append(node* linkedList,node *temp)
{
	if(!linkedList)
		return temp;
	node *traverse;
	traverse=linkedList;
	while(traverse->link)
		traverse=traverse->link;
	traverse->link=temp;
	return linkedList;
}
int pathExists(int a,int b,node *neighbours[])
{
	node *head,*tail,*toQueue,*temp;
	head=tail=NULL;
	int recentlyRemoved,found=0;
	toQueue=newNode(a,0);
	head=tail=toQueue;
	visited[a]=1;
	while(head)
	{
		recentlyRemoved=head->destination;
		if(head==tail)
			tail=head=head->link;
		else
			head=head->link;
		temp=neighbours[recentlyRemoved];
		while(temp)
		{
			if(!visited[temp->destination])
			{
				if(temp->destination==b)
				{
					found=1;
					break;
				}
				toQueue=newNode(temp->destination,0);
				visited[temp->destination]=1;
				if(!head&&!tail)
					head=tail=toQueue;
				else
				{
					tail->link=toQueue;
					tail=tail->link;
				}
			}
			temp=temp->link;
		}
		if(found)
			break;
	}
	return found;
}
void insertMin(mh temp)
{
	minCount++;
	min[minCount]=temp;
	int now=minCount;
	while(min[now/2].weight>temp.weight)
	{
		min[now]=min[now/2];
		now/=2;
	}
	min[now]=temp;
}
mh deleteMin()
{
	mh minElement,lastElement;
	int child,now;
	minElement=min[1];
	lastElement=min[minCount--];
	for(now=1;2*now<=minCount;now=child)
	{
		child=now*2;
		if(child!=minCount&&min[child+1].weight<min[child].weight)
			child++;
		if(lastElement.weight>min[child].weight)
			min[now]=min[child];
		else
			break;
	}
	min[now]=lastElement;
	return minElement;
}
mh newMh(int l,int w)
{
	mh temp;
	temp.location=l;
	temp.weight=w;
	return temp;
}
int eppstein(int start,int end,node *neighbours[])
{
	mh recentlyRemoved,begin=newMh(start,0);
	insertMin(begin);
	int dcount=0,dijk;
	while(dcount!=2)
	{
		recentlyRemoved=deleteMin();
		if(recentlyRemoved.location==end)
		{
			if(!dcount)
			{
				dijk=recentlyRemoved.weight;
				dcount=1;
			}
			else if(dijk!=recentlyRemoved.weight)
			{
				dcount++;
				break;
			}
		}
		node *temp;
		temp=neighbours[recentlyRemoved.location];
		while(temp)
		{
			if(temp->frequency<3)
			{
				temp->frequency++;
				begin=newMh(temp->destination,recentlyRemoved.weight+temp->weight);
				insertMin(begin);
			}
			temp=temp->link;
		}
	}
	return recentlyRemoved.weight;
}
int main()
{
	int t,n,r,i,u,v,w;
	scanf("%d",&t);
	while(t--)
	{
		minCount=0;
		min[0].weight=-2147483647;
		min[0].location=-2147483647;
		scanf("%d%d",&n,&r);
		node *reach[5500];
		for(i=0;i<5500;i++)
		{
			reach[i]=NULL;
			visited[i]=0;
		}
		for(i=0;i<r;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			reach[u]=append(reach[u],newNode(v,w));
			reach[v]=append(reach[v],newNode(u,w));
		}
		if(pathExists(1,n,reach))
			printf("%d\n",eppstein(1,n,reach));
		else
			printf("-1\n");
		node *clean,*del;
		for(i=0;i<5500;i++)
		{
			if(reach[i])
			{
				clean=reach[i];
				while(clean)
				{
					del=clean;
					clean=clean->link;
					free(del);
				}
			}
			reach[i]=NULL;
		}
	}
	return 0;
}
