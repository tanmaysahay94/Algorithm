#include<stdio.h>
int main()
{
	long long int n,i,num,sum=0;
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&num);
		sum+=num;
	}
	if(sum==n*(n+1)/2)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
