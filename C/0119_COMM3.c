#include<stdio.h>
#include<math.h>
int main()
{
	int t;
	float r,ax,ay,bx,by,cx,cy,dab,dbc,dac;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f%f%f%f%f%f%f",&r,&ax,&ay,&bx,&by,&cx,&cy);
		dab=sqrt(pow(ax-bx,2)+pow(ay-by,2));
		dbc=sqrt(pow(cx-bx,2)+pow(cy-by,2));
		dac=sqrt(pow(ax-cx,2)+pow(ay-cy,2));
		if((dab>r&&(dbc>r||dac>r))||(dbc>r&&(dac>r||dab>r))||(dac>r&&(dab>r||dbc>r)))
			printf("no\n");
		else
			printf("yes\n");
	}
	return 0;
}
