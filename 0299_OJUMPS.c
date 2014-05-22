#include<stdio.h>
int main()
{
	unsigned long long v;
	scanf("%llu",&v);
	v%=6;
	if(!v||v==1||v==3)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
