#include<stdio.h>							
int cmp(const void *a,const void *b)					//Main Algorithm: Keep the difference (sum of 2 sides, 3rd side) about the same.
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,i,side[2100],count,start,end;
	scanf("%d",&n);
	while(n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&side[i]);
		qsort(side,n,sizeof(int),cmp);
		count=0;
		for(i=n-1;i>=2;i--)
		{
			start=0;
			end=i-1;
			while(start<end)
			{
				if(side[start]+side[end]<side[i])	//Elements being added: [start:a(0)] ................. [end:a(n-2)] [i:a(n-1)]
				{
					count+=(end-start);
					++start;			//If sum of 2 sides is GREATER than the third, I want to REDUCE that difference!
				}
				else
					--end;				//If sum of 2 sides is LESSER than the third, I want to INCREASE that difference!
			}
		}
		printf("%d\n",count);
		scanf("%d",&n);
	}
	return 0;
}
