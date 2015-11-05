#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	char c;
	struct node *link;
}node;
int main()
{
	int i,balance=1;
	char s[696969];
	node *top,*new;
	top=NULL;
	printf("Input the bracket string: ");
	scanf("%s",s);
	for(i=0;s[i];i++)
	{
		if(!i)
		{
			new=(node*)malloc(sizeof(node));
			new->c=s[i];
			new->link=NULL;
			top=new;
		}
		else
		{
			if(s[i]=='('||s[i]=='{'||s[i]=='[')
			{
				new=(node*)malloc(sizeof(node));
				new->c=s[i];
				new->link=top;
				top=new;
			}
			else if(s[i]==')'||s[i]=='}'||s[i]==']')
			{
				if(s[i]==')')
				{
					if(top->c=='(')
						top=top->link;
					else
					{
						balance=0;
						break;
					}
				}
				else if(s[i]=='}')
				{
					if(top->c=='{')
						top=top->link;
					else
					{
						balance=0;
						break;
					}
				}
				else if(s[i]==']')
				{
					if(top->c=='[')
						top=top->link;

					else
					{
						balance=0;
						break;
					}
				}
			}
		}
	}
	if(!balance)
		printf("Not balanced\n");
	else
	{
		if(top==NULL)
			printf("Balanced\n");
		else
			printf("Not balanced\n");
	}
	return 0;
}
