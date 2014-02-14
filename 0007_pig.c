#include<stdio.h>
int main()
{
	int t;
	long long int N,d,min,max;
	scanf("%d",&t);
	while(t>0)
	{
		scanf("%lld %lld",&N,&d);
		if(N<=d)
			min=0;
		else 
			min=N-d;
		if(d%2==1)
			d++;
		d/=2;
		max=N-d;
		printf("%lld %lld\n",min,max);
		t--;
	}
	return 0;
}
