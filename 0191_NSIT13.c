#include<stdio.h>
int main()
{
	int i,j,n,mod,map[42],c,k;
	for(i=0;i<10;i++)
	{
		c=0;
		for(j=0;j<42;j++)
			map[j]=0;
		for(j=0;j<10;j++)
		{
			scanf("%d",&n);
			if(!map[mod=n%42])
			{
				map[mod]=1;
				c++;
			}
		}
		printf("%d\n",c);
	}
	return 0;
}
