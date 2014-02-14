#include<stdio.h>
int c(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,a[150],i,m;
	scanf("%d",&t);
	while(t--)
	{
		m=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(int),c);
		for(i=1;i<n;i++)
			m+=a[i]-a[0];
		printf("%d\n",m);
	}
	return 0;
}
