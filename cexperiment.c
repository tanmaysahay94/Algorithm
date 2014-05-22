#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	long long x,y;
	struct node *link;
}node;
node *a[100005];
node *newnode(int a)
{
	node *t=malloc(sizeof(node));
	t->x=a;
	t->y=1;		//1 and not 0 because if something is on the list, it means that it's been incremented (on the matrix) at least once
	t->link=NULL;
	return t;
}
node *insert(node *list,long long val)
{
	if(!list)
		return newnode(val);
	else if(val>=list->x)
	{
		if(val==list->x)
		{
			list->y++;
			return list;
		}
		node *toInsert=newnode(val);
		toInsert->link=list;
		return toInsert;
	}
	else
	{
		node *temp=list;
		while(temp->link&&temp->link->x>val)
			temp=temp->link;
		if(temp->link&&temp->link->x==val)
			temp->link->y++;
		else
		{
			node *toInsert=newnode(val);
			toInsert->link=temp->link;
			temp->link=toInsert;
		}
		return list;
	}
}
int main()
{
	node *k=NULL;
	k=insert(k,10);
	k=insert(k,5);
	k=insert(k,7);
	k=insert(k,24);
	k=insert(k,51);
	k=insert(k,5);
	k=insert(k,5);
	k=insert(k,7);
	k=insert(k,1);
	k=insert(k,3);
	k=insert(k,6);
	k=insert(k,2);
	k=insert(k,3);
	k=insert(k,2);
	k=insert(k,1);
	k=insert(k,51);
	k=insert(k,24);
	k=insert(k,10);
	node *t=k;
	while(t)
	{
		printf("val: %lld frequency: %lld\n",t->x,t->y);
		t=t->link;
	}
	return 0;
}
