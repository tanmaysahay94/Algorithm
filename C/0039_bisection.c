#include<stdio.h>
#include<math.h>
double f(double c,double p[],int deg)
{
	double val=0.0;
	int i;
	for(i=0;i<deg;i++)
		val+=p[i]*(pow(c,i));
	return val;
}
void root(double m,double n,double q[],int degree)
{
	double s,t,u,root,check;
	int iteration=1,found=0;
	s=f(m,q,degree);
	t=f(n,q,degree);
	if(!(s*t))
	{
		found=1;
		if(!s)
			root=m;
		else
			root=n;
	}
	else
	{
		check=fabs(m-n);
		while(check>0.001)
		{
			if(s*t<0)
			{
				u=(m+n)/2;
				if(f(u,q,degree)*s>0)
					m=u;
				else
					n=u;
				check=fabs(m-n);
				if(check<0.001)
				{
					found=1;
					root=(m+n)/2;
				}
			}
			else
				found=0;
		}
	}
	if(found)
		printf("A root is %.6lf\n",root);
	else
		printf("No root exists in the given interval.\n");
}
int main()
{
	int d,i;
	printf("Enter degree of the expression:");
	scanf("%d",&d);
	d++;
	double e[d],a,b;
	for(i=d-1;i>-1;i--)
	{
		printf("Enter coefficient of x^%d:",i);
		scanf("%lf",&e[i]);
		printf("\n");
	}
	printf("Enter lower limit:");
	scanf("%lf",&a);
	printf("Enter upper limit:");
	scanf("%lf",&b);
	root(a,b,e,d);
	return 0;
}
