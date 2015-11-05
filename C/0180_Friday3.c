#include<stdio.h>
int main()
{
	long int t,i,curr,max,n;
	scanf("%ld",&t);
	while(t--)
	{
		curr=max=0;
		scanf("%ld",&n);
		long int a[n];
		for(i=0;i<n;i++)
		{
			scanf("%ld",a+i);
			if(a[i]>=0)
				curr+=a[i];
			else
				curr=0;
			max=curr>max?curr:max;
		}
		printf("%ld\n",max);
	}
	return 0;
}
