#include<stdio.h>
int main()
{
	long long int size,i,no_of_queries,query,start,end,middle;
	scanf("%lld",&size);
	long long int arn[size];
	for(i=0;i<size;i++)
		scanf("%lld",&arn[i]);
	scanf("%lld",&no_of_queries);
	while(no_of_queries--)
	{
		scanf("%lld",&query);
		start=0;
		end=size-1;
		middle=(start+end)/2;
		while(start<=end)
		{
			if(query>arn[middle])
				start=middle+1;
			else if(query==arn[middle])
			{
				printf("%lld\n",middle);
				break;
			}
			else
				end=middle-1;
			middle=(start+end)/2;
		}
		if(start>end)
			printf("-1\n");
	}
	return 0;
}
