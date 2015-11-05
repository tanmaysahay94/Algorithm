#include<stdio.h>
int main()
{
	int t,n,g[100001],i,j,max;
	scanf("%d",&t);
	while(t--)
	{
		max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&g[i]);
			for(j=0;j<i;j++)
			{
				if(g[i]-g[j]>max)
					max=g[i]-g[j];
			}
		}
		if(!max)
			printf("UNFIT\n");
		else
			printf("%d\n",max);
	}
	return 0;
}
