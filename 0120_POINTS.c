#include<stdio.h>
#include<math.h>
typedef struct point
{
	double x,y;
}pt;
int cmp(const void *a,const void *b)
{
	if((*(pt*)a).x==(*(pt*)b).x)
		return (*(pt*)b).y-(*(pt*)a).y;
	return (*(pt*)a).x-(*(pt*)b).x;
}
int main()
{
	int t,n,i;
	double distance;
	scanf("%d",&t);
	while(t--)
	{
		distance=0;
		scanf("%d",&n);
		pt p[n];
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		qsort(p,n,sizeof(pt),cmp);
//		for(i=0;i<n;i++)
//			printf("%f %f\n",p[i].x,p[i].y);
		for(i=0;i<n-1;i++)
			distance+=sqrt(pow(p[i].x-p[i+1].x,2)+pow(p[i].y-p[i+1].y,2));
		printf("%.2lf\n",distance);
//		printf("\n");
	}
	return 0;
}
