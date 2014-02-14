#include<stdio.h>
int main()
{
	int T;
	long long int n,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&n);
		sum=81*(n/9)+(n%9)*(n%9);
		printf("%lld\n",sum);
		sum=0;
	}
	return 0;
}
