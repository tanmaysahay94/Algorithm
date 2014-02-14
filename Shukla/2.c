#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

char preStack[10000];
char opStack[10000];

int isOperator(char data)
{
    return (data=='+'||data=='-'||data=='/'||data=='*'||data=='^');
}
//CHECK PARANTHESES
int isOperand(char data)
{
    return (data>='0'&&data<='9');
}

int isBrace(char a)
{
	return a=='('||a==')';
}

int precedence(char operator)
{
	if(operator=='+'||operator=='-')
		return 1;
	if(operator=='/'||operator=='*')
		return 2;
	if(operator=='^')
		return 3;
	if(operator=='('||operator==')')
		return 0;//4
}

/*int operation(int operand1,int operand2,char operation)
{
    //printf("op1: %d, op2: %d\n",operand1,operand2);
    if(operation=='+')
        return operand1+operand2;
    if(operation=='-')
        return operand1-operand2;
    if(operation=='/')
        return operand1/operand2;
    if(operation=='*')
        return operand1*operand2;
    if(operation=='^')
        return pow(operand1,operand2);
}*/

int isBalanced(char s[])
{
	int n1=0;
	int n2=0;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]==')')
			n1++;
		if(s[i]=='(')
			n2++;
	}
	return n1==n2;
}

int main()
{	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int opIndex=0;
		int preIndex=0;
		char input[100];
		char lastScanned=0;
		scanf("%s",input);
		//printf("%s\n",input);
		int len=strlen(input);
		//printf("%c\n",input[0]);
		int i,flag=0;
		if(!isBalanced(input))
		{
			printf("invalid\n");
			continue;
		}
		if(isOperator(input[0])||isOperator(input[len-1]))
		{
			printf("invalid\n");
			continue;
		}
		if(input[0]==')'||input[len-1]=='(')
		{
			printf("invalid\n");
			continue;
		}
		for(i=len-1;i>=0;i--)
		{
			//printf("%c %c\n",lastScanned,input[i]);
			//__________________
			if(isOperator(lastScanned)&&isOperator(input[i]))
			{
				//printf("1\n");
				flag=1;
				break;
			}
			if(isOperand(lastScanned)&&isOperand(input[i]))
			{
				//printf("2\n");
				flag=1;
				break;
			}
/*			if(lastScanned==')'&&isOperator(input[i]))
			{
				flag=1;
				break;
			}
			if((lastScanned=='(')&&isOperand(input[i]))
			{
				flag=1;
				break;
			}
*/			//__________________
			if(input[i]==')')
			{
				opIndex++;
				opStack[opIndex]=input[i];
			}
			if(isOperand(input[i]))
			{
				//printf("operand\n");
				preIndex++;
				preStack[preIndex]=input[i];
			}
			if(isOperator(input[i]))
			{
				//printf("operator\n");
				if(opIndex==0)
				{
					opIndex++;
					opStack[opIndex]=input[i];
				}
				else
				{
					//printf("operator else loop\n");
					while(precedence(opStack[opIndex])>precedence(input[i]))
					{
						//printf("dubious loop\n");
						preIndex++;
						preStack[preIndex]=opStack[opIndex];
						opIndex--;
					}
					if(opStack[opIndex]=='^'&&input[i]=='^')
					{
						preIndex++;
						preStack[preIndex]=opStack[opIndex];
						opIndex--;
					}
					//preIndex++;
					//preStack[preIndex]=opStack[opIndex];//?
					//opIndex--;
					opIndex++;
					opStack[opIndex]=input[i];
				}
			}
			if(input[i]=='(')
			{
				while(opStack[opIndex]!=')')
				{
					preIndex++;
					preStack[preIndex]=opStack[opIndex];
					opIndex--;
				}
				opIndex--;//to ignore )
			}
			lastScanned=input[i];
		}
		lastScanned=0;
		while(opIndex>0&&flag==0)
		{
			//printf("final loop\n");
			preIndex++;
			preStack[preIndex]=opStack[opIndex];
			opIndex--;
		}
		int j;
		if(flag==0)
		{
		for(j=preIndex;j>0;j--)
		{
			//printf("preIndex is %d\n",preIndex);
			printf("%c",preStack[j]);
		}
		printf("\n");
		}
		else
		{
			printf("invalid\n");
		}
		//printf("%d %d\n",opIndex,preIndex);
		//printf("exec done\n");
	}
	return 0;
}
