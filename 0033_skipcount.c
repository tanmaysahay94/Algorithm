#include<stdio.h>
int main()
{
	int T,N,x,a[10000],flag[10000],i,j=0,count;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&x);
		count=N;
		for(i=0;i<N;i++)
		{
			scanf("%d",&a[i]);
			flag[i]=0;
		}
		if(N==1)
			printf("%d\n",a[0]);
		else
			printf("%d ",a[0]);
		flag[0]=1;
		count--;
		i=1; 							
		j=0;
		while(j<x&&count)						//loop to print one element at a time
		{
			if(i==N)     			                      //not incrementing j as flag[0] is always 1
				i=0;
			if(flag[i]==0)
			{
				j++;						//j never incremented by more than 1 in each iteration
				if(j==x)
				{
					flag[i]=1;
					if(count!=1)
						printf("%d ",a[i]);
					else
						printf("%d\n",a[i]);
					count--;
					j=0;
				}
			}
			i++;
		}
	}
	return 0;
}
