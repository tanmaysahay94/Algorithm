#include<stdio.h>
#include<math.h>
#define e 0.0000001
int main()
{
	double a,c,b;
	scanf("%lf",&b);
	a=b;
	c=1-b;
	do{
		a*=(1+0.5*c);
		c=pow(c,2)*(0.75+0.25*c);
	}while(c>e);
	printf("%lf",a);
	return 0;
}
