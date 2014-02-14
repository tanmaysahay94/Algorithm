#include<stdio.h>
int main()
{
	double a,b,c,d,e,v,r,r1,r2,i,ia,ib,ic,id,ie;
	int n;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&v);
		r1=(a*b)/(a+b);
		r2=(c*d*e)/((c*d)+(d*e)+(e*c));
		r=r1+r2;
		i=v/r;
		ia=(i*b)/(a+b);
		ib=(i*a)/(a+b);
		ic=(i*d*e)/((c*d)+(d*e)+(e*c));
		id=(i*e*c)/((c*d)+(d*e)+(e*c));
		ie=(i*c*d)/((c*d)+(d*e)+(e*c));
		printf("%.1lf %.1lf %.1lf %.1lf %.1lf\n",ia,ib,ic,id,ie);
		n--;
	}
	return 0;
}
