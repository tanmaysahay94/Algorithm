#include<stdio.h>
int main()
{
	int t,n,g[100001],i,b[100001],c[100001],max,min,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=0;
		scanf("%d",&n);
		scanf("%d",g);
		min=c[0]=g[0];
		for(i=1;i<n;i++)
		{
			scanf("%d",&g[i]);
			min=min<g[i]?min:g[i];
			c[i]=min;
		}
		max=g[n-1];
		for(i=n-2;i>=0;i--)
		{
			max=max>g[i]?max:g[i];
			b[i]=max;
		}
		for(i=0;i<n;i++)
			ans=ans>b[i]-c[i]?ans:b[i]-c[i];
		if(!ans)
			printf("UNFIT\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
