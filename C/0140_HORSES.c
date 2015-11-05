#include<stdio.h>
int cmp(void const *a, void const *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,i,min,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",a+i);
		qsort(a,n,sizeof(int),cmp);
		min=a[n-1];
		for(i=0;i<n-1;i++)
			min=(d=a[i+1]-a[i])<min?d:min;
		printf("%d\n",min);
	}
}
