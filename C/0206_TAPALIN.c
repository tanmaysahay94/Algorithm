#include<stdio.h>
#define mod 1000000007
long long int power(long long int base,long long int exp)
{
	long long int p=1;
	while(exp>0)
	{
		if(exp&1)
			p=(p*base)%mod;
		base=(base*base)%mod;
		exp>>=1;
	}
	return p;
}
int main()
{
	long long int t,n,a;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		a=((power(26,n/2)-1)*power(25,mod-2))%mod;
		a=(a*52)%mod;
		if(n&1)
			a=(a+power(26,n/2+1))%mod;
		printf("%lld\n",a);
	}
	return 0;
}
