#include<stdio.h>
int main()
{
	long int t,n,k,i,j,f;
	scanf("%ld",&t);
	while(t--)
	{
		f=0;
		scanf("%ld",&n);
		long int a[n];
		for(i=0;i<n;i++)
			scanf("%ld",&a[i]);
		scanf("%ld",&k);
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]+a[j]==k)
				{
					f=1;
					break;
				}
			}
			if(f)
				break;
		}
		if(f)
			printf("found\n(%ld, %ld)\n",a[i],a[j]);
		else
			printf("not found\n");
	}
	return 0;
}
