#include<stdio.h>
#include<math.h>
int main()
{
	int N,t;
	double X,R,P;
	scanf("%d",&N);
	while(N>0)
	{
		scanf("%lf %d %lf",&X,&t,&R);
		t*=12;
		P=X/pow((1+(R/1200)),t);
		printf("%.2lf\n",P);
		N--;
	}
	return 0;
}
