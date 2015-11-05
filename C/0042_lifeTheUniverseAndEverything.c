#include<stdio.h>
int main()
{
	long long int j;
	scanf("%lld",&j);
	while(j!=42)
	{
		printf("%lld\n",j);
		scanf("%lld",&j);
	}
	return 0;
}
