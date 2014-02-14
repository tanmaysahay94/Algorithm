#include<stdio.h>
unsigned int rev(unsigned int n)
{
	unsigned int bit,i,reverse=0;
	bit=sizeof(n)*8;
	for(i=0;i<bit;i++)
		if(n&(1<<i))
			reverse|=1<<((bit-1)-i);
	return reverse;
}
int main()
{
	unsigned int a,b;
	unsigned long int sum;
	while(scanf("%u%u",&a,&b)!=EOF)
	{
		sum=(unsigned long int)rev(a)+(unsigned long int)rev(b);
		printf("%lu\n",sum);
		sum=0;
		getchar();
	}
	return 0;
}
