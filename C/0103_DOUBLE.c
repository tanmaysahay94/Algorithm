#include <stdio.h>
int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n&1)
			printf("%d\n",n-1);
		else
			printf("%d\n",n);
	}
	return 0;
} 
