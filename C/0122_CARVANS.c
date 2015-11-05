#include<stdio.h>
int main()
{
	int t,n,i,min,max_speed;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int car[n];
		for(i=0;i<n;i++)
			scanf("%d",&car[i]);
		max_speed=n;
		min=car[0];
		for(i=0;i<n-1;i++)
		{
			if(car[i+1]>min)
				--max_speed;
			else if(car[i+1]<min)
				min=car[i+1];
		}
		printf("%d\n",max_speed);
	}
	return 0;
}
