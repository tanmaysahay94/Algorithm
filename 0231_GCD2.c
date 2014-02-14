#include<stdio.h>
int gcd(int a,int b)
{
	int r=0;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int remainder(char b[],int a)
{
	int rem=0,i;
	for(i=0;b[i];i++)
	{
		rem=10*rem+(b[i]-'0');
		rem%=a;
	}
	return rem;
}
int main()
{
	int t,a;
	char b[300];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s",&a,b);
		if(!a)
			printf("%s\n",b);
		else
			printf("%d\n",gcd(a,remainder(b,a)));
	}
	return 0;
}
