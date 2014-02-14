#include<stdio.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int t,k,n,w[200],ans,sumFirst,sumLast,total,i;
	scanf("%d",&t);
	while(t--)
	{
		sumFirst=sumLast=total=0;
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			scanf("%d",w+i);
		qsort(w,n,sizeof(int),cmp);
		for(i=0;i<k;i++)
			sumFirst+=w[i];
		for(i=n-1;i>=n-k;i--)
			sumLast+=w[i];
		for(i=0;i<n;i++)
			total+=w[i];
		printf("%d\n",max(abs(2*sumFirst-total),abs(2*sumLast-total)));
	}
	return 0;
}
