#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	int n;
	scanf("%d",&n);
	while(n)
	{
		printf("%d\n",n&2);
		scanf("%d",&n);
	}
	return 0;
}
