#include<stdio.h>
int main()
{
	double P,pay;
	int n,Y;
	scanf("%d",&Y);
	while(Y>0)
	{
		scanf("%lf %d",&P,&n);
		pay=P/10;
		while(n>0)
		{
			P*=1.12;
			P-=pay;
			n--;
		}
		printf("%.6lf\n",P);
		Y--;
	}
	return 0;
}
