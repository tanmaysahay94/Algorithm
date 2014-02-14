#include<stdio.h>
#define mod 1000000007
int main()
{
	unsigned long long int u,i,total=3,triTotal=4,opp;
	scanf("%llu",&u);
	for(i=1;i<u;i++)
	{
		opp=(triTotal%mod-total%mod)%mod;
		total=(total%mod*3)%mod+opp%mod;
		triTotal=(triTotal%mod*4)%mod;
	}
	printf("%llu\n",total);
	return 0;
}
