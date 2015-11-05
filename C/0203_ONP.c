#include<stdio.h>
int main()
{
	int t,i,sCount,pCount;
	char inFix[1000],stack[1000],postFix[1000];
	scanf("%d",&t);
	while(t--)
	{
		sCount=pCount=0;
		scanf("%s",inFix);
		for(i=0;inFix[i];i++)
		{
			if(inFix[i]=='('||inFix[i]=='+'||inFix[i]=='-'||inFix[i]=='*'||inFix[i]=='/'||inFix[i]=='^')
			{
				stack[sCount++]=inFix[i];
				stack[sCount]='\0';
			}
			else if(inFix[i]==')')
			{
				postFix[pCount++]=stack[sCount-1];
				sCount-=2;
			}
			else
				postFix[pCount++]=inFix[i];
		}
		postFix[pCount]='\0';
		printf("%s\n",postFix);
	}
	return 0;
}
