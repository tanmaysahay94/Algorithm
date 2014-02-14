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
		scanf("%d",a);
		g=*a;
		for(i=1;i<n;i++)
		{
			scanf("%d",a+i);
			g=gcd(g,a[i]);
		}
		printf("%d\n",g);
	}
	return 0;
} 
