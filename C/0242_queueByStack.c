#include<stdio.h>
#include<stdlib.h> 
#include<math.h>
#include<string.h>
int stack1[100000]; 
int stack2[100000];
int top1=-1, top2=-1; 
void push(int token) 
{ 
	char a='y';
	if(top2==-1)
	{
		do
		{ 
			printf("\nEnter the token to be inserted: ");
			scanf("%d",&token);
			top1=top1+1;
			stack1[top1]=token;
			printf("Do you want to continue insertion?(y/n) ");
			scanf("%c%c",&a,&a);
		}
		while(a=='y');
	}
	else
	{ 
		while(top2!=-1)
		{
			top1=top1+1;
			stack1[top1]=stack2[top2];
			top2=top2+1;
		}
		do
		{
			printf("\nEnter the token to be inserted: ");
			scanf("%d",&token);
			top1=top1+1;
			stack1[top1]=token;
			printf("Do you want to continue insertion?(y/n)");
			getchar();
			scanf("%c",&a);
		}
		while(a=='y'||a=='Y');
	}
} 
int pop()
{
	int value; 
	while(top1!=-1)
	{
		top2=top2+1;
		stack2[top2]=stack1[top1];
		top1=top1-1;
	}
	value=stack2[top2];
	top2=top2-1;
	while(top2!=-1)
	{ 
		top1=top1+1;
		stack1[top1]=stack2[top2];
		top2=top2-1;
	} 
	return value;
}
void display()
{
	int i;
	printf("\nThe Stack elements are: ");
	for(i=0;i<=top1;i++)
		printf("%d   ",stack1[i]); 
}
int main()
{
	char ch , a='y';
	int choice, token;
	printf("1.Insert");
	printf("\n2.Delete");
	printf("\n3.Display");
	do
	{
		printf("\nEnter your choice for the operation: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push(token);
				display();
				break;
			case 2: token=pop();
				printf("\nThe token deleted is %d",token);
				display();
				break;
			case 3: display();
				break;
			default:printf("Wrong choice");
				break;
		}
		printf("\nDo you want to continue?(y/n): ");
		getchar();
		scanf("%c",&ch);
	} 
	while(ch=='y'||ch=='Y');
	return 0;
}
