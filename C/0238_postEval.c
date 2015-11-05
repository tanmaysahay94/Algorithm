#include<stdio.h>
#include<math.h>
#include<stdlib.h>
typedef struct stack
{
	char data;
	struct stack *link;
}stack;
int main()
{
	char expr[10000];
	int i,a;
	stack *head,*temp;
	head=NULL;
	printf("Input the expression to evaluate: ");
	scanf("%s",expr);
	for(i=0;expr[i];i++)
	{
		if(expr[i]>='0'&&expr[i]<='9')
		{
			if(head==NULL)
			{
				temp=(stack*)malloc(sizeof(stack));
				temp->data=expr[i]-'0';
				temp->link=NULL;
				head=temp;
			}
			else
			{
				temp=(stack*)malloc(sizeof(stack));
				temp->data=expr[i]-'0';
				temp->link=head;
				head=temp;
			}
		}
		else
		{
			a=head->data;
			head=head->link;
			if(expr[i]=='^')
				head->data=pow(head->data,a);
			else if(expr[i]=='*')
				head->data*=a;
			else if(expr[i]=='/')
				head->data/=a;
			else if(expr[i]=='+')
				head->data+=a;
			else if(expr[i]=='-')
				head->data-=a;
		}
	}
	printf("%d\n",head->data);
	return 0;
}
