#include<stdio.h>
int main()
{
	int t,ds,dt,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&ds,&dt,&d);
		if(d>=ds+dt)
			printf("%d\n",d-ds-dt);
		else if(ds>=d+dt)
			printf("%d\n",ds-d-dt);
		else if(dt>=d+ds)
			printf("%d\n",dt-d-ds);
		else
			printf("0\n");
	}
	return 0;
}
