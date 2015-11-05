#include<stdio.h>
int main()
{
	int T;
	long long int a,b,c,s,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&n);
		if(n==1)
			printf("%lld\n",a);
		else if(n==2)
			printf("%lld\n",b);
		else if(n==3)
			printf("%lld\n",c);
		else
		{
			for(i=4;i<=n;i++)
			{
				s=a+b+c;
				a=b;
				b=c;
				c=s;
			}
			printf("%lld\n",c);
		}
	}
	return 0;
}
