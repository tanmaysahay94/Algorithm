#include<stdio.h>
int main()
{
	int t,d,p1,p2,r1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&d);
		if(d<0)
		{
			p1=d/10;
			r1=d%10;
			p2=10*(p1/10)+r1;
			printf("%d\n",p1=p1>p2?p1:p2);
		}
		else
			printf("%d\n",d);
	}
	return 0;
}
