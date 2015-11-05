#include<stdio.h>
#include<stdlib.h>
int main()
{
	long long int t,n,count,val,twoCount;
	scanf("%lld",&t);
	while(t--)
	{
		twoCount=count=0;
		scanf("%lld",&n);
		while(n--)
		{
			scanf("%lld",&val);
			if(val>1)
			{
				count++;
				twoCount+=(val==2);
			}
		}
		printf("%lld\n",(count*(count-1)-twoCount*(twoCount-1))/2);
	}
	return 0;
}
