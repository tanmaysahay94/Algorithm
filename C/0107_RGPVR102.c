#include <stdio.h>

int main()
{
	int t,n,team[70][2],i,points,max;
	scanf("%d",&t);
	while(t--)
	{
		max=-1;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&team[i][0]);
		for(i=0;i<n;i++)
		{
			scanf("%d",&team[i][1]);
			points=3*team[i][0]+team[i][1];
			max=points>max?points:max;
		}
		printf("%d\n",max);
	}
	return 0;
} 
