#include<stdio.h>
#include<math.h>
int main()
{
	long long int total,limit,chambers,digit,base,i;
	scanf("%lld%lld%lld",&total,&limit,&chambers);
	digit=chambers+1;
	int num[digit];
	base=limit+1;
	total=total%(long long int)(pow(base,digit));
	for(i=0;i<chambers;i++)
	{
		num[i]=total%(long long int)base;
		total/=base;
	}
	for(i=0;i<chambers-1;i++)
		printf("%d ",num[i]);
	printf("%d\n",num[i]);
	printf("\n");
	return 0;
} 
