#include<stdio.h>
unsigned long long int Power(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int c=1;
	while(b>0)
	{
		if(b&1)
			c*=a;
		a*=a;
		b>>=1;
	}
	return c;
}
int main()
{
	unsigned long long int base,power;
	printf("Base:");
	scanf("%llu",&base);
	printf("Power:");
	scanf("%llu",&power);
	printf("%llu\n",Power(base,power));
	return 0;
}
