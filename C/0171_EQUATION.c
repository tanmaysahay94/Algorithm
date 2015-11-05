#include<stdio.h> 
long long int f(long long int n)
{
	if(n>=0)
		return((n+3)*(n+2)*(n+1))/6;
	else
		return 0;
}
 
int main()
{
	long long int t,N,A,B,C,count;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&N,&A,&B,&C);
		count=f(N)-f(N-A-1)-f(N-B-1)-f(N-C-1)+f(N-A-B-2)+f(N-B-C-2)+f(N-A-C-2)-f(N-A-B-C-3);
		printf("%lld\n",count);
	}
	return 0 ;
}
