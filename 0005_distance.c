#include<stdio.h>
#include<math.h>
int main()
{
	double x1,x2,y1,y2,o[999];
	int N,i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	{
		scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
		o[i]=sqrt(pow((x2-x1),2)+pow((y2-y1),2));
	}
	for(i=0;i<N;i++)
		printf("%.1lf\n",o[i]);
	return 0;
}
