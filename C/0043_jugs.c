#include<stdio.h>
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
int main()
{
	int a,b,c,t,a1,b1,sum,step1,step2;
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
	{
		if(c==0)
			printf("0\n");
		else if(c==a||c==b)
			printf("1\n");
		else if((c>a&&c>b)||c%gcd(a,b))
			printf("-1\n");
		else
		{
			a1=0;
			b1=0;
			step1=0;
			while(a1!=c&&b1!=c)
			{
				if(!a1)
				{
					a1=a;
					step1++;
				}
				else if(b1==b)
				{
					b1=0;
					step1++;
				}
				else
				{
					sum=a1+b1;
					b1=sum<b?sum:b;
					a1=sum-b1;
					step1++;
				}
			}
			a1=0;
			b1=0;
			step2=0;
			while(a1!=c&&b1!=c)
			{
				if(!b1)
				{
					b1=b;
					step2++;
				}
				else if(a1==a)
				{
					a1=0;
					step2++;
				}
				else
				{
					sum=a1+b1;
					a1=sum<a?sum:a;
					b1=sum-a1;
					step2++;
				}
			}
			if(step1<step2)
				printf("%d\n",step1);
			else
				printf("%d\n",step2);
		}
	}
	return 0;
}
