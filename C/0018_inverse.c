#include<stdio.h>
#define e 0.0000001
int main()
{
	double a,c,x;
	scanf("%lf",&x);
	a=1;
	c=1-x;     //initial values
	do
	{
		a*=(1+c);
		c*=c;
	}while(c>e);
	printf("%lf\n",a);  //printing the inverse
	return 0;
}
