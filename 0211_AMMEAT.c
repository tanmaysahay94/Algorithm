#include<stdio.h>
int main()
{
	int t,n,i,j;
	long long int m,p[10],food,temp;
	scanf("%d",&t);
	while(t--)
	{
		food=0;
		scanf("%d%lld",&n,&m);
		for(i=0;i<n;i++)
			scanf("%lld",p+i);
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
			{
				if(p[i]<p[j])
				{
					temp=p[i];
					p[i]=p[j];
					p[j]=temp;
				}
			}
		for(i=0;i<n;i++)
		{
			food+=p[i];
			if(food>=m)
				break;
		}
		if(food<m)
			printf("-1\n");
		else
			printf("%d\n",i+1);
	}
	return 0;
}
