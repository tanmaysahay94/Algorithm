#include<stdio.h>
int main()
{
	int t,n,c;
	scanf("%d",&t);
	while(t--)
	{
		c=0;
		scanf("%d",&n);
		while(n>1)
		{
			n>>=1;
			c++;
		}
		while(c--)
			n<<=1;
		printf("%d\n",n);
	}
	return 0;
}
