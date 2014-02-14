#include<stdio.h>
#include<string.h>
int isOp(char a)
{
	return a=='+'||a=='-'||a=='*'||a=='/'||a=='^';
}
int isNum(char a)
{
	return a>='0'&&a<='9';
}
int main()
{
	char e[150],out[150],stack[150],scan;
	int j,t,i,index,invalid,top;
	scanf("%d",&t);
	while(t--)
	{
		index=0;
		invalid=0;
		top=0;								//where I am adding the element
		scanf("%s",e);
		invalid=isOp(e[0])||isOp(e[strlen(e)-1]);
		if(invalid)
		{
			printf("invalid\n");
			continue;
		}
		for(i=strlen(e)-1;i>=0;i--)
		{
			if(i)
				invalid=(isOp(e[i])&&isOp(e[i-1]))||(isNum(e[i])&&isNum(e[i-1]));
			if(invalid)
				break;
			scan=(e[i]=='(')*')'+(e[i]==')')*'('+(!(e[i]=='('||e[i]==')'))*e[i];
			if(isOp(scan)||scan=='(')
			{
				if(scan=='^'||scan=='*'||scan=='/')
					while(top>0&&stack[top-1]=='^')
						out[index++]=stack[--top];	//popping before pushing
				else if(scan=='+'||scan=='-')
					while(top>0&&(stack[top-1]=='^'||stack[top-1]=='*'||stack[top-1]=='/'))
						out[index++]=stack[--top];	//popping before pushing
				stack[top++]=scan;				//pushing after popping required stuff
			}
			else if(scan==')')					//popping when closing bracket encountered
			{
				while(top>0&&stack[top-1]!='(')
					out[index++]=stack[--top];
				top--;
			}
			else if(isNum(scan))
				out[index++]=scan;
		}
		for(i=top-1;i>=0;i--)
			out[index++]=stack[i];
		if(invalid)
			printf("invalid");
		else
			for(i=index-1;i>=0;i--)
				printf("%c",out[i]);
		printf("\n");
	}
	return 0;
}
