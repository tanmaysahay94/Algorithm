#include<stdio.h>
int main()
{
	long long int t,a,b;
	scanf("%lld",&t);
	while(t--)
		printf("%lld\n",scanf("%lld",&a)*a+scanf("%lld",&b)*b);
	return 0;
}
