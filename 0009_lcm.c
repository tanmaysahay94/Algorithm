#include<stdio.h>
int main()
{
	int N;
	long long int a,b,lcm,p,r,t;
	scanf("%d",&N);
	for(;N>0;N--)
	{
		scanf("%lld %lld",&a,&b);
		if(a==0||b==0)
		{
			if(a==0)
				lcm=b;
			else if(b==0)
				lcm=a;
		}
		else
		{
			p=a*b;
			if(a<b)
			{
				t=a;
				a=b;
				b=t;
			}
			while(b!=0)
			{
				r=a%b;
				a=b;
				b=r;
			}
			lcm=p/a;
		}
		printf("%lld\n",lcm);
	}
	return 0;
}
