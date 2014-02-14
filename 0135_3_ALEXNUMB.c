#include<stdio.h>
int main()
{
	long long int t,n,i,l;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",n*(n-1)/2);
		for(i=0;i<n;i++)
			scanf("%lld",&l);
	}
	return 0;
}
