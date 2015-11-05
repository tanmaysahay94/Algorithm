#include<stdio.h>
int gcd(int p,int q)
{
	int r;
	while(q)
	{
		r=p%q;
		p=q;
		q=r;
	}
	return p;
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",gcd(a-1,b-1)+1);
	}
	return 0;
}
