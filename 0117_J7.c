#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	double p,s,k,vol;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf",&p,&s);
		k=(p-(sqrt(pow(p,2)-24*s)))/12;
		vol=k*(s/2-k*(p/4-k));
		printf("%.2lf\n",vol);
	}
	return 0;
}
