#include<stdio.h>
int main()
{
	unsigned int N,P,T,X;
	scanf("%u",&T);
	while(T--)
	{
		scanf("%u%u",&N,&P);
		X=N>>(32-P);
		N<<=P;
		N|=X;
		printf("%u\n",N);
	}
	return 0;
}
