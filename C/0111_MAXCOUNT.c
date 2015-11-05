#include<stdio.h>
int main()
{
	int arr[100];
	int t,n,count,count1,x,i,j;
	scanf("%d",&t);
	while(t--)
	{
		count1=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		for(i=0;i<n;i++)
		{
			count=0;
			for(j=i;j<n;j++)
			{
				if(arr[i]==arr[j])
					count++;
			}
			if(count>count1)
			{count1=count;
				x=arr[i];}
			if(count==count1&&arr[i]<x)
				x=arr[i];
		}
		printf("%d %d\n",x,count1);
	}
	return 0;
} 
