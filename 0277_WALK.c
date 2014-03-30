#include<stdio.h>
int main()
{
	int t,n,i,ans;
	scanf("%d",&t);
	while(t--)
	{
		ans=!scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=n-1;i;i--)
		{
			ans=a[i]>=ans?a[i]:ans;
			ans++;
		}
		ans=a[0]>=ans?a[0]:ans;
		printf("%d\n",ans);
	}
	return 0;
}
