#include<stdio.h>
#define inf 100000000
int min(int a,int b)
{
	return a<b?a:b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i,n,k,a[1000005],b[500005],ans=inf;
	for(i=0;i<500005;i++)
		b[i]=inf;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
		b[a[i]]=min(b[a[i]],min(i+1,n-i));		//b[a[i]] is current least distance of a[i] and it is being updated
	for(i=1;i<=k;i++)
		if(!(b[i]==inf||b[k-i]==inf||i==k-i))
			ans=min(ans,max(b[i],b[k-i]));		//as both indices must sum up to k, but must be DISTINCT
	if(ans==inf)
		printf("-1\n");
	else
		printf("%d\n",ans);
	return 0;
}
