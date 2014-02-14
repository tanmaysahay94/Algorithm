#include<stdio.h>
int main()
{
	int i,t,n,min,best,g[100001];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",&g[0]);
		min=g[0];
		best=0;
		for(i=1;i<n;i++)
		{
			scanf("%d",&g[i]);
			min=min<g[i]?min:g[i];
			best=best>g[i]-min?best:g[i]-min;
		}
		if(!best)
			printf("UNFIT\n");
		else
			printf("%d\n",best);
	}
	return 0;
}
