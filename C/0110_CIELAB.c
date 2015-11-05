#include<stdio.h>
int main()
{
	int a,b,diff;
	scanf("%d%d",&b,&a);
	diff=b-a;
	if(diff%10==9)
		diff--;
	else
		diff++;
	printf("%d\n",diff);
	return 0;
} 
