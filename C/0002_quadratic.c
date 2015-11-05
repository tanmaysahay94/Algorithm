#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	double a,b,c;
	double d,r1,r2,t;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%lf %lf %lf",&a,&b,&c);
		d=pow(b,2)-(4*a*c);
		if(d>=0)
		{
			d=sqrt(d);
			r1=(-b+d)/(2*a);
			r2=(-b-d)/(2*a);
			if(r1>r2)
			{
				t=r1;
				r1=r2;
				r2=t;
			}
			printf("%.2lf %.2lf\n",r1,r2);
		}
		else
		{
			d=-1*d;
			d=sqrt(d);
			r1=(-b)/(2*a);
			r2=d/(2*a);
			printf("%.2lf",r1);
			printf(" - i%.2lf",r2);
			printf(",");
			printf("%.2lf",r1);
			printf(" + i%.2lf\n",r2);
		}
		n--;
	}
	return 0;
}
