#include<stdio.h>
#define m 1000000007
int main()
{
	int t,i,j;
	unsigned long long int a[3];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<3;i++)
			scanf("%llu",a+i);
		for(i=0;i<2;i++)
			for(j=i+1;j<3;j++)
				if(a[i]>a[j])
					a[i]=a[i]+a[j]-(a[j]=a[i]);
		printf("%llu\n",((a[0]%m)*((a[1]-1)%m)%m*((a[2]-2)%m)%m)%m);
	}
	return 0;
}
