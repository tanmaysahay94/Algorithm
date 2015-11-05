#include <stdio.h>
#define n 1000
void main(void) 
{
	float i,x,y,a,b,sum=0;
	printf("\nThis program will integrate a function between two boundary limits.");
	printf("\n\nEnter the first boundary limit:");
	scanf("%f", &a);
	printf("\nEnter the second boundary limit:");
	scanf("%f", &b);
	if(a>b) 
	{
		i=a;
		a=b;
		b=i;
	}
	for(i=a;i<b;i+=(b-a)/n)
	{/*function definition below*/
		y=x*x+2*x-4;
		sum+=y*(b-a)/n;
	}
	printf("\n\nValue of integration is:%.3f",sum);
	getch();
	return;
}
