#include<stdio.h>
#include<math.h>
int main()
{
	unsigned long long int t,l,d,s,c;
	scanf("%llu",&t);
	while(t--)
	{
		scanf("%llu%llu%llu%llu",&l,&d,&s,&c);
		if((s*pow(c+1,d-1))>=l)
			printf("ALIVE AND KICKING\n");
		else
			printf("DEAD AND ROTTING\n");
	}
	return 0;
}
