#include<stdio.h>
int main()
{
	int n,i,j,q,query,min,count;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	scanf("%d",&q);
	while(q--)
	{
		count=0;
		scanf("%d",&query);
		for(i=0;i<n;i++)			//picking a start point in the subarray
		{
			min=a[i];
			for(j=i;j<n;j++)
			{
				if(a[j]<min)
					min=a[j];
				if(min==query)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
