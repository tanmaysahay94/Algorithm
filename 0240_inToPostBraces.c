#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char val;
	struct node *next;
} node;
void push(char c, node *a)
{
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp->val=c;
	temp->next=a->next;
	a->next=temp;
}
char top(node *a)
{
	if(a->next!=NULL)
		return a->next->val;
	else
		return 'a';
}
char pop(node *a)
{
	node *temp;
	if(a->next!=NULL)
	{
		temp = a->next;
		a->next = a->next->next;
		return temp->val;
	}
	else
		return 'd';
}
void convert_in_2_pos(char *s,node *op)
{
	int i,len=strlen(s);
	char c;
	for(i=0;i<len;++i)
	{
		if(s[i]=='^')
		{
			if(top(op)=='^'&&top(op)!='(')
			{
				while((c=pop(op))!='d')
				{    
					putchar(c);
					if(top(op)=='(')
						break;
				}
			}
			push(s[i],op);
		}
		else if((s[i]=='-'||s[i]=='+'))
		{
			if(top(op)!='(')
			{
				while((c=pop(op))!='d')
				{
					putchar(c);
					if(top(op)=='(')
						break;
				}
			}
			push(s[i],op);
		}
		else if((s[i]=='/'||s[i]=='*'))
		{
			if((top(op)=='^'|| top(op) == '/' || top(op) == '*') && top(op) != '(')
				while( (c = pop(op)) != 'd')
				{
					putchar(c);
					if( top(op) == '(' )
						break;
				}
			push( s[i], op );

		}
		else if( s[i] == '(' )
		{
			push( s[i], op );
		}
		else if( s[i] == ')' )
		{
			while( (c = pop(op)) != '(' )
				putchar(c);
		}
		else
			putchar(s[i]);
	}

	while( (c = pop(op)) != 'd' )
		putchar(c);
	putchar('\n');
}
int main()
{
	char s[100];
	node *stack = (node *)malloc( sizeof( stack ) );
	if( stack == NULL )
	{
		printf("Insufficient Memory\n");
		return 0;
	}
	stack->next = NULL;
	scanf("%s", s); 
	convert_in_2_pos( s, stack );
	return 0;
}
