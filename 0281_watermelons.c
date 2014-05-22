#include<stdio.h>
int main()
{
	int w;
	scanf("%d",&w);
	if(w>=4&&!(w&1))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
