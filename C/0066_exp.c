#include<stdio.h>
long long int p(int m,int n)
{
	if(!n)
		return 1;
	else if(n==1)
		return m;
	int t=n/2;
	long long int k=p(m,t)%1000000007;
	if(n%2)
		return (m*((k*k)%1000000007))%1000000007;
	else
		return (k*k)%1000000007;
}
int main()
{
	int T,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&a,&b);
		printf("%lld\n",p(a,b)%1000000007);
	}
	return 0;
}
