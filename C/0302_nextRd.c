#include<stdio.h>
int main()
{
	int n,k,i,zero=0;
	scanf("%d%d",&n,&k);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<k;i++)
		if(!a[i])
		{
			zero=1;
			break;
		}
	if(!zero)
		for(;i<n;i++)
			if(a[i]!=a[i-1])
				break;
	printf("%d\n",i);
}
