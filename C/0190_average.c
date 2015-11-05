#include<stdio.h>
int main()
{
	float m,t;
	int i,a;
	i=1;
	t=0;
	scanf("%f",&m);
	while((int)m!=-1)
	{
		t+=m;
		if(!(i%4))
		{
			printf("%.2f\n",t/4);
			i=t=0;
		}
		scanf("%f",&m);
		i++;
	}
	return 0;
}
