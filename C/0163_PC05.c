#include<math.h>
#include<stdio.h>
int digSum(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int isPrime(int n)
{
	int i,c;
	int itLim=sqrt(n);
	if(n==1)
		return 0;
	else if(n==2||n==3)
		return 1;
	else
	{
		c=0;
		if(n%6==1||n%6==5)
		{
			for(i=3;i<=itLim;i+=2)
				if(!(n%i))
				{
					c=1;
					break;
				}
		}
		else
			return 0;
	}
	return !c;
}
int main()
{
	int t,l,i,u,co;
	scanf("%d",&t);
	while(t--)
	{
		co=0;
		scanf("%d%d",&l,&u);
		for(i=l;i<=u;i++)
			if(isPrime(digSum(i)))
				co++;
		printf("%d\n",co);
	}
	return 0;
}
