#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,k,nQuery,open=0;
	scanf("%d%d",&n,&k);
	int status[1010]={0};
	char wQuery[20];
	while(k--)
	{
		scanf("%s",wQuery);
		if(!strcmp(wQuery,"CLOSEALL"))
		{
			for(i=0;i<1010;i++)
				status[i]=0;
			open=0;
		}
		else if(!strcmp(wQuery,"CLICK"))
		{
			scanf("%d",&nQuery);
			if(!status[nQuery-1])
				open++;
			else
				open--;
			status[nQuery-1]=!status[nQuery-1];
		}
		printf("%d\n",open);
	}
	return 0;
}
