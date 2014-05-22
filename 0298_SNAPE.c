#include<stdio.h>
#include<math.h>
void p(float v)
{
	if(floor(v)==v)
		printf("%.1f",v);
	else
		printf("%g",v);
}
int main()
{
	int t,b,ls;
	float x,y;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&b,&ls);
		x=sqrt(fabs(pow(b,2)-pow(ls,2)));
		y=sqrt(fabs(pow(b,2)+pow(ls,2)));
		p(x);
		printf(" ");
		p(y);
		printf("\n");
	}
}
