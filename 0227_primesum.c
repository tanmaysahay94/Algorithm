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
	unsigned long long int i,s=0;
	for(i=1;i<2000000;i++)
		if(isPrime(i))
			s+=i;
	printf("%llu\n",s);
	return 0;
}
