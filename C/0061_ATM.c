#include<stdio.h>
int main()
{
	int b;
	float w;
	scanf("%d%f",&b,&w);
	if((!(b%5))&&(w>=(float)b+0.5))
		printf("%.2f\n",w-(float)b-0.5);
	else
		printf("%.2f\n",w);
	return 0;
} 
