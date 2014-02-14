#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	unsigned long long int height;
	struct node *next;
}node;
int cmp(const void *a,const void *b)
{
	return *(unsigned long long int*)a-*(unsigned long long int*)b;
}
int main()
{
	int t;
	unsigned long long int total,i,move,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu",&total);
		unsigned long long int ppl[total];
		node *temp,*head,*tail,*del;
		head=tail=NULL;
		for(i=0;i<total;i++)
			scanf("%llu",ppl+i);
		qsort(ppl,total,sizeof(unsigned long long int),cmp);
		for(i=0;i<total;i++)		//populating the circular linked list
		{
			temp=(node*)malloc(sizeof(node));
			temp->height=ppl[i];
			temp->next=NULL;
			if(head==NULL)
				head=tail=temp;
			else
			{
				tail->next=temp;
				tail=tail->next;
			}
		}
		tail->next=head;		//circular linked list created
		scanf("%llu",&move);
		move--;
		while(total>1)
		{
			k=move%total;
			for(i=1;i<=k;i++)
				tail=tail->next;
			del=tail->next;
			free(del);
			head=tail->next=tail->next->next;
			total--;
		}
		printf("%llu\n",head->height);
	}
	return 0;
}
