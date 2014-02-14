#include<stdio.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,i,n,a[110],query,searchFor,start,end,middle,found;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d",&query);
		searchFor=a[query-1];
		qsort(a,n,sizeof(int),cmp);
		start=0;
		end=n-1;
		middle=(start+end)/2;
		while(start<=end)
		{
			if(searchFor>a[middle])
				start=middle+1;
			else if(searchFor==a[middle])
			{
				found=middle;
				break;
			}
			else
				end=middle-1;
			middle=(start+end)/2;
		}
		printf("%d\n",++found);
	}
	return 0;
}
