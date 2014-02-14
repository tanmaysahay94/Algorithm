#include<stdio.h>
int main()
{
	long long int n,i,j,sum=0;
	scanf("%lld",&n);
	long long int a[n];
	for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
	for(i=0;i<n-1;i++)
	{
		if(a[i])
		{
			for(j=i+1;j<n;j++)
			{
				if(a[j])
					sum+=(a[i]&a[j]);
				else
					break;
			}
		}
		else
			break;
	}
	printf("%lld\n",sum);
	return 0;
}
