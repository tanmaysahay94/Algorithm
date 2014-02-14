#include<stdio.h>
long long int rev(long long int n)
{
	long long int r=0;
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
	long long int t,a,b;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		printf("%lld\n",rev(a)+rev(b));
	}
	return 0;
}
