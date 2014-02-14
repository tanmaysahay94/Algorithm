#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct stack
{
	char d;
	struct stack *l; 
}stack;
int main()
{
	char in[10000];
	stack *head,*temp;
	head=NULL;
	int i,count=0,k;
	printf("Input the expression to be evaluated: ");
	scanf("%s",in);
	k=strlen(in);
	for(i=0;i<=k;i++)
	{
		if(in[i]=='('||in[i]=='^'||in[i]=='*'||in[i]=='/'||in[i]=='+'||in[i]=='-')
		{
			if(head==NULL)
			{
				temp=(stack*)malloc(sizeof(stack));
				temp->d=in[i];
				temp->l=NULL;
				head=temp;
			}
			else
			{
				if(in[i]=='^')
				{
					while((head!=NULL)&&(head->d=='^'||head->d=='('))                       //Popping Conditions
					{
						if(head->d=='^')
							printf("%c",head->d);
						head=head->l;
					}
					temp=(stack*)malloc(sizeof(stack));
					temp->d=in[i];
					temp->l=head;
					head=temp;
				}
				else if(in[i]=='*'||in[i]=='/')
				{
					while((head!=NULL)&&(head->d=='^'||head->d=='*'||head->d=='/'||head->d=='('))
					{
						if(head->d!='(')
							printf("%c",head->d);
						head=head->l;
					}
					temp=(stack*)malloc(sizeof(stack));
					temp->d=in[i];
					temp->l=head;
					head=temp;
				}
				else if(in[i]=='-'||in[i]=='+')
				{
					while((head!=NULL)&&(head->d=='^'||head->d=='*'||head->d=='/'||head->d=='+'||head->d=='-'||head->d=='('))
					{
						if(head->d!='(')
							printf("%c",head->d);
						head=head->l;
					}
					temp=(stack*)malloc(sizeof(stack));
					temp->d=in[i];
					temp->l=head;
					head=temp;
				}
			}
		}
		else if(in[i]==')')
		{
			while(head!=NULL&&head->d!='(')
			{
				printf("%c",head->d);
				head=head->l;
			}
			if(head->d=='(')
				head=head->l;
		}
		else if(in[i]=='\0')
		{
			while(head!=NULL)
			{
				printf("%c",head->d);
				head=head->l;
			}
		}
		else
			printf("%c",in[i]);
	}
	printf("\n");
	return 0;
}
