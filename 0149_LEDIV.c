#include<math.h>
#include<stdio.h>
inline int read()
{
	int n=0;
	char c;
	while((c=getchar_unlocked())<'0');
	n+=(c-'0');
	while((c=getchar_unlocked())>='0')
		n=(n<<3)+(n<<2)+(c-'0');
	return n;
}
int gcd(int a,int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int isPrime(int num)
{
	int s,c,j;
	s=sqrt(num);
	if(num==1||num==0)
		return 0;
	else if(num==2||num==3)
		return 1;
	else if((num)%6==1||(num)%6==5)
	{
		c=0;
		for(j=3;j<=s;j+=2)
		{
			if(!(num%j))
			{
				c=1;
				break;
			}
		}
		return !c;
	}
	else
		return 0;
}
int main()
{
	int t,n,a[100005],i,g;
	t=read();
	while(t--)
	{
		n=read();
		g=a[0]=read();
		for(i=1;i<n;i++)
		{
			a[i]=read();
			g=gcd(g,a[i]);
		}
		if(g==1)
			printf("-1\n");
		else if(!(g%2))
			printf("2\n");
		else if(isPrime(g))
			printf("%d\n",g);
		else
		{
			for(i=3;i<g;i++)
				if(!(g%i))
					break;
			printf("%d\n",i);
		}
	}
	return 0;
}
