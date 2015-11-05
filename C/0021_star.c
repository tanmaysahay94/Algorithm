#include<stdio.h>
int main()
{
	int i,j,n,spaces;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		spaces=n-i-1;
		for(j=0;j<spaces;j++)
			printf(" ");
		for(j=0;j<=i;j++)
			printf("* ");
		printf("\n");
	}
	return 0;
}
