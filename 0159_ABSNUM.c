#include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		printf("%d\n",(n>=0)*n+(-1)*(n<0)*n);
	}
	return 0;
}
