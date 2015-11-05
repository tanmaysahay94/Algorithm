#include<stdio.h>
#include<math.h>
int main()
{
	long long int a,m,c,d,num;
	int n;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%lld %lld",&a,&m);
		c=0;
		num=0;
		while(a>0)
		{
			d=a%2;
			if(d==1)
				c++;
			a/=2;
		}
		while(c>0)
		{
			num+=pow(m,(c-1));
			c--;
		}
		printf("%lld\n",num);
		n--;
	}
	return 0;
}
