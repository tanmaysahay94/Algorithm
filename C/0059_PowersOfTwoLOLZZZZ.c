#include<stdio.h>
int main()
{
	unsigned long long int t,n;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu",&n);
		if(!(n&(n-1)))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
