#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int digit;
	struct node *link;
}num;
int main()
{
	char c;
	num *a,*b;
	a=NULL;
	b=NULL;
	int i;
	printf("Input the first number:");
	num *new_node1,*current1;
	c=getchar();
	while(c>='0'&&c<='9')
	{	
		new_node1=(struct node*)malloc(sizeof(struct node));
		current1=(struct node*)malloc(sizeof(struct node));
		new_node1->digit=c-'0';
		new_node1->link=NULL;
		if(a==NULL)
		{
			a=new_node1;
			current1=new_node1;
		}
		else
		{
			current1->link=new_node1;
			current1=current1->link;		
		}
		c=getchar();
	}
	num *t;
	t=a;
	while(t!=NULL)
	{
		printf("%d",t->digit);
		t=t->link;
	}
	/*
	num *new_node2,*current2;
	for(i=0;num2[i];i++)
	{	
		new_node2=(struct node*)malloc(sizeof(struct node));
		current2=(struct node*)malloc(sizeof(struct node));
		new_node2->digit=num2[i]-'0';
		new_node2->link=NULL;
		if(b==NULL)
		{
			b=new_node2;
			current2=new_node2;
		}
		else
		{
			current2->link=new_node2;
			current2=current2->link;		
		}
	}
        num *p1=a;
	num *q1=NULL;
	num *r1;
	while(p1!=NULL)
	{
		r1=q1;
		q1=p1;
		p1=p1->link;
		q1->link=r1;
	}
	a=q1;
        num *p2=b;
	num *q2=NULL;
	num *r2;
	while(p2!=NULL)
	{
		r2=q2;
		q2=p2;
		p2=p2->link;
		q2->link=r2;
	}
	b=q2;
	num *sum=NULL;
        num *current3,*new_node3;
	int t_sum,t_carry=0;
	while(a!=NULL&&b!=NULL)
	{
		t_sum=(t_carry+a->digit+b->digit)%10;
		t_carry=(t_carry+a->digit+b->digit)/10;
		new_node3=(num*)malloc(sizeof(num));
		current3=(struct node*)malloc(sizeof(struct node));
		new_node3->digit=t_sum;
		if(sum==NULL)
		{
			sum=new_node3;
			current3=new_node3;
		}
		else
		{
			current3->link=new_node3;
			current3=current3->link;		
		}
	}
	while(a!=NULL)
	{
		t_sum=(t_carry+a->digit)%10;
		t_carry=(t_carry+a->digit)/10;
		new_node3=(struct node*)malloc(sizeof(struct node));
		new_node3->digit=t_sum;
		current3=(struct node*)malloc(sizeof(struct node));
		if(sum==NULL)
		{
			sum=new_node3;
			current3=new_node3;
		}
		else
		{
			current3->link=new_node3;
			current3=current3->link;
		}
	}
	while(b!=NULL)
	{
		t_sum=(t_carry+b->digit)%10;
		t_carry=(t_carry+b->digit)/10;
		new_node3=(struct node*)malloc(sizeof(struct node));
		new_node3->digit=t_sum;
		current3=(struct node*)malloc(sizeof(struct node));
		if(sum==NULL)
		{
			sum=new_node3;
			current3=new_node3;
		}
		else
		{
			current3->link=new_node3;
			current3=current3->link;
		}
	}
        num *p3=sum;
	num *q3=NULL;
	num *r3;
	while(p3!=NULL)
	{
		r3=q3;
		q3=p3;
		p3=p3->link;
		q3->link=r3;
	}
	sum=q3;
	num *t;
	t=sum;
	while(t)
	{
		printf("%d",t->digit);
		t=t->link;
	}
	printf("\n");*/
	return 0;
}
