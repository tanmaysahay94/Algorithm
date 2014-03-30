#include<stdio.h>
#include<math.h>
int main()
{
	double m,n,a;
	unsigned long long int l,b;
	scanf("%lf%lf%lf",&m,&n,&a);
	l=(unsigned long long)ceil(m/a);
	b=(unsigned long long)ceil(n/a);
	printf("%llu\n",l*b);
	return 0;
}
