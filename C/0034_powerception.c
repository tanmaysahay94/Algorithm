#include<stdio.h>
unsigned long long int p(unsigned long long int a,unsigned long long int b)
{
	unsigned long long int d,c;
	if (b==0)
		return 1;
	else if (!(b%2))
	{
		c=p(a,(b/2));
		d=c*c;
	}
	else
	{
		c=p(a,(b/2));
		d=a*c*c;
	}
	return d;
}
void main()
{
	unsigned long long int x,y;
	scanf("%llu%llu",&x,&y);
	printf("%llu\n",p(x,y));
}
