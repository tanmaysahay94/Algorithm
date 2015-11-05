#include<stdio.h>
int main()
{
	unsigned long long int n,k,t,c=0;
	scanf("%llu%llu",&n,&k);
	while(n--)
	{
		scanf("%llu",&t);
		if(!(t%k))
			c++;
	}
	printf("%llu\n",c);
	return 0;
} 
