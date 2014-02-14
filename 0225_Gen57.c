#include<stdio.h>
unsigned long long int num(unsigned long long int n)
{
	unsigned long long int i,gen=0;
	for(i=1;i<=15;i++)
	{
		if(n%2)
			gen=gen*10+7;
		else
			gen=gen*10+5;
		n>>=1;
	}
	return gen;
}
int main()
{
	unsigned long long int i,c=0;
	for(i=0;i<=32767;i++)
	{
		printf("%llu\n",num(i));
		if(!(num(i)%35))
			c++;
	}
	printf("%llu\n",c);
	return 0;
}
