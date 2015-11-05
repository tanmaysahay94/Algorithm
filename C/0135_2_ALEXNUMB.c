#include<stdio.h>
int main()
{
	long long int t,n,i,a[100500],sumUpToN;
	scanf("%lld",&t);
	while(t--)
	{
		for(i=0;i<100500;i++)
			a[i]=0;
		scanf("%lld",&n);
		sumUpToN=0;
		for(i=1;i<n;i++)
			sumUpToN+=i;
		printf("%lld\n",sumUpToN);
		for(i=0;i<n;i++)
			scanf("%lld",&a[i]);
	}
	return 0;
}
