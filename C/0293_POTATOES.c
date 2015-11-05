#include<stdio.h>
#include<math.h>
int isPrime(unsigned long long int n)
{
	unsigned long long int i,p=1,s=sqrt(n);
	if(!n||n==1)
		return 0;
	else if(n==2||n==3)
		return 1;
	else if(!(n%2)||!(n%3))
		return 0;
	else
	{
		if(n%6==1||n%6==5)
		{
			for(i=3;i<=s;i+=2)
				if(!(n%i))
				{
					p=0;
					break;
				}
		}
		else
			return 0;
	}
	return p;
}
int main()
{
	unsigned long long int t,x,y,lowLim,i;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu%llu",&x,&y);
		lowLim=x+y;
		for(i=lowLim+1;i<=2003;i++)
			if(isPrime(i))
			{
				printf("%llu\n",i-lowLim);
				break;
			}
	}
	return 0;
}
