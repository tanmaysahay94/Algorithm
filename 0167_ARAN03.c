#include<stdio.h>
int digSum(int a)
{
	int sum=0;
	while(a)
	{
		sum+=a%10;
		a/=10;
	}
	return sum;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",n%digSum(n));
	}
	return 0;
}
