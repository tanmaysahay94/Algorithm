#include<stdio.h>//sum of two numbers
int main()
{
	int i,j,a,b;
	int c[1000];
	scanf("%d",&i);
	for(j=0;j<i;j++)
	{
		scanf("%d %d",&a,&b);
		c[j]=a+b;
	}
	for(j=0;j<i;j++)
		printf("%d\n",c[j]);
	return 0;
}
