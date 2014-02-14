#include<stdio.h>
int rev(int n)
{
	int r=0;
	while(n)
	{
		r*=10;
		r+=n%10;
		n/=10;
	}
	return r;
}
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",rev(rev(a)+rev(b)));
	}
	return 0;
}
