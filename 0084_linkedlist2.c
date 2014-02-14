#include<stdio.h>
typedef struct list
{
	int n;
	struct list *next;
}node;
int main()
{
	node *start,*curr,*prev;
	int n,m;
	scanf("%d",&n);
	start=(node*)malloc(sizeof(node));
	scanf("%d",&start->n);
	prev=start;
	n--;
	while(n--)
	{
		curr=(node*)malloc(sizeof(node));
		scanf("%d",&curr->n);
		prev->next=curr;
		prev=curr;
	}
	while(start!=NULL)
	{
		printf("%d ",start->n);
		start=start->next;
	}
	return 0;
}
