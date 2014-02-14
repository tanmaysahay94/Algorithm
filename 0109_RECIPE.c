#include<stdio.h>
int gcd(int p,int q)
{
	int r;
	while(q>0)
	{
		r=p%q;
		p=q;
		q=r;
	}
	return p;
}
int main()
{
	int t,n,i,g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		g=a[0];
		for(i=1;i<n;i++)
			g=gcd(g,a[i]);
		for(i=0;i<n-1;i++)
			printf("%d ",a[i]/g);
		printf("%d\n",a[i]/g);
	}
	return 0;
} 
