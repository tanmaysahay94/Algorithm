#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int cmp(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,i,start,middle,end,query;
	srand(time(NULL));
	printf("No of elements: ");
	scanf("%d",&n);
	int arn[n];
	for(i=0;i<n;i++)
	{
		arn[i]=rand()%1000;
		printf("%d ",arn[i]);
	}
	printf("\n");
	qsort(arn,n,sizeof(int),cmp);
	printf("Sorted Array\n");
	for(i=0;i<n-1;i++)
		printf("%d ",arn[i]);
	printf("%d\n",arn[i]);
	start=0;
	end=n-1;
	middle=(n-1)/2;
	printf("Input query: ");
	scanf("%d",&query);
	while(start<=end)
	{
		if(query>arn[middle])
			start=middle+1;
		if(query==arn[middle])
			break;
		if(query<arn[middle])
			end=middle-1;
		middle=(start+end)/2;
	}
	if(start>end)
		printf("Not Found\n");
	else
		printf("Found value %d at index: %d\n",arn[middle],middle);
	return 0;
}
