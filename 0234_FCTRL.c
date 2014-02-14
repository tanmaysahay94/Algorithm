#include <stdio.h>
#include <math.h>
int main()
{
	long long int t,n,iterate,zeros;
	scanf("%lld",&t);
	while(t--){
		zeros=0;
		scanf("%lld",&n);
		if(n>=30517578125)iterate=15;
		else if(n>=6103515625)iterate=14;
		else if(n>=1220703125)iterate=13;
		else if(n>=244140625)iterate=12;
		else if(n>=48828125)iterate=11;
		else if(n>=9765625)iterate=10;
		else if(n>=1953125)iterate=9;
		else if(n>=390625)iterate=8;
		else if(n>=78125)iterate=7;
		else if(n>=15625)iterate=6;
		else if(n>=3125)iterate=5;
		else if(n>=625)iterate=4;
		else if(n>=125)iterate=3;
		else if(n>=25)iterate=2;
		else if(n>=5)iterate=1;
		else iterate=0;
		while(iterate)zeros+=n/pow(5,iterate--);
		printf("%lld\n",zeros);
	}
	return 0;
}
