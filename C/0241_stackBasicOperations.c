#include<stdlib.h>
#include<stdio.h>
typedef struct plate
{
	int data;
	struct plate *link;
}plate;
plate *top=NULL;
void push(plate **top,int value)
{
	plate *temp;
	temp=(plate*)malloc(sizeof(plate));
	temp->data=value;
	if(top==NULL)
	{
		temp->link=NULL;
		*top=temp;
	}
	else
	{
		temp->link=*top;
		*top=temp;
	}
}
int popVal(plate *top)
{
	return top->data;
}
plate *popPointer(plate *top)
{
	top=top->link;
	return top;
}
void display(plate *top)
{
	plate *traverse;
	traverse=top;
	while(traverse!=NULL)
	{
		printf("%d ",traverse->data);
		traverse=traverse->link;
	}
	printf("\n");
}
int main()
{
	int choice,value;
	char ch;
	printf("The following is the list of operations:\n1. Push\n2. Pop\n3. Display\n4. Quit\n");
	do
	{
		scanf("Input a number: ");
		scanf("%d",&choice);
		if(choice==1)
		{
			printf("Value to push: ");
			scanf("%d",&value);
			push(&top,value);
		}
		else if(choice==2)
			printf("Value popped: %d Top at: %p\n",popVal(top),top=popPointer(top));
		else if(choice==3)
			display(top);
		else if(choice==4)
			return 0;
		printf("Do you want to continue? (y/n): ");
		scanf("%c%c",&ch,&ch);
	}while(ch=='y'||ch=='Y');
}
