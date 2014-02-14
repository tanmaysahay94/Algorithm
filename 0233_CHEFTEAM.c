#include<stdio.h>
unsigned long long int c(unsigned long long int n,unsigned long long int k)
{
	if(!k||n==k)
		return 1;
	else
		return c(n-1,k)+c(n-1,k-1);
}
int main()
{
	int t;
	unsigned long long int n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%llu%llu",&n,&k);
		printf("%llu\n",c(n,k));
	}
	return 0;
}
