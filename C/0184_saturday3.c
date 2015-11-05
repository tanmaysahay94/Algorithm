#include<stdio.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i,a[n],found=0;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	qsort(a,n,sizeof(int),cmp);
	i=n-1;
	while(i>=2)
	{
		if(a[i]==a[i-1])
			i-=2;
		else
		{
			found=1;
			break;
		}
	}
	if(found)
		printf("%d\n",a[i]);
	else
		printf("%d\n",*a);
	return 0;
}
