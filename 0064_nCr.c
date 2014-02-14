#include<stdio.h>
int mem[1500][1500]={0};
int c(int n,int r)
{
	if(!mem[n][r])
	{
		if(n==r||!r)
			mem[n][r]=1;
		else
			mem[n][r]=(c(n-1,r)%1000000007+c(n-1,r-1)%1000000007);
	}
	return mem[n][r];
}
int main()
{
	int T,N,R;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&R);
		printf("%d\n",c(N,R)%1000000007);
	}
	return 0;
}
