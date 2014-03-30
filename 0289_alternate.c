#include<stdio.h>
#include<stdlib.h>
int main()
{
	int testTakers=0,qualified,numberOfQueries,query,input,high[500000],low[500000];
	scanf("%d",&numberOfQueries);
	while(numberOfQueries--)
	{
		scanf("%d",&query);
		if(query==1)
		{
			qualified=testTakers/4;
			if(!qualified)
				printf("-1\n");
			else
			{
			}
		}
		else if(query==2)
		{
			scanf("%d",&input);
			testTakers++;
			if(!(testTakers%4))
			{
				if(input>high[0])
				{
				}
			}
			else
			{
			}
		}
	}
	return 0;
}
