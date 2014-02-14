#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
} *start=NULL;
void create()
{
	char ch;
	do
	{
		struct node *new_node,*current;
		new_node=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&new_node->data);
		new_node->link=NULL;
		if(start==NULL)
		{
			start=new_node;
			current=new_node;
		}
		else
		{
			current->link=new_node;
			current=current->link;		
		}
		getchar();
		printf("Do you want to create another node?");
		scanf("%c",&ch);
	}while(ch!='n');
}
void display()
{
	struct node *traverse;
	printf("The linked list is: ");
	traverse=start;
	while(traverse!=NULL)
	{
		printf("%d--->",traverse->data);
		traverse=traverse->link;
	}
	printf("NULL\n");
}
void reverse()
{
	struct node *p=start;
	struct node *q=NULL;
	struct node *r;
	while(p!=NULL)
	{
		r=q;
		q=p;
		p=p->link;
		q->link=r;
	}
	start=q;
}
int main()
{
	create();
	display();
	printf("Reversed list:\n");
	reverse();
	display();
	return 0;
}
