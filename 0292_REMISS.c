#include<stdio.h>
unsigned long long int max(unsigned long long int x,unsigned long long int y)
{
	return x>y?x:y;
}
int main()
{
	unsigned long long int t,a,b;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu%llu",&a,&b);
		printf("%llu %llu\n",max(a,b),a+b);
	}
	return 0;
}
