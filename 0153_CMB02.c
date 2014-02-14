#include<stdio.h>
unsigned long long int isPalin(unsigned long long int n)
{
	int b=n,r=0;
	while(n)
	{
		r*=10;
		r+=n%10;
		n/=10;
	}
	if(b==r)
		return 1;
	return 0;
}
int main()
{
	unsigned long long int t,a;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu",&a);
		while(!isPalin(++a));
		printf("%llu\n",a);
	}
	return 0;
}
