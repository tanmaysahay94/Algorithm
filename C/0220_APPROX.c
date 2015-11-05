#include<stdio.h>
int main()
{
	int t,i,rem,k;
	scanf("%d",&t);
	while(t--)
	{
		rem=46870;
		scanf("%d",&k);
		if(!k)
			printf("3");
		else
		{
			printf("3.");
			for(i=1;i<=k;i++)
			{
				printf("%d",rem/33102);
				rem=(rem%33102)*10;
			}
		}
		printf("\n");
	}
	return 0;
}
