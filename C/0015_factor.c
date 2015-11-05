#include<stdio.h>
int main()
{
	int a,b,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		if((a%b==0) || (b%a==0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
