#include<stdio.h>
int cmp(const void *a,const void *b)
{
	return *(int*)b-*(int*)a;
}
int main()
{
	int d,i,t,n,inCount,a[200],out[200],count,outCount;
	scanf("%d",&t);
	while(t--)
	{
		count=outCount=0;
		scanf("%d",&inCount);
		while(inCount--)
		{
			scanf("%d",&d);
			if(!(d&1))
				a[count++]=d;
		}
		qsort(a,count,sizeof(int),cmp);
		for(i=0;i<count-1;i++)
			if(a[i]!=a[i+1])
				out[outCount++]=a[i];
		out[outCount++]=a[count-1];
		for(i=0;i<outCount-1;i++)
			printf("%d ",out[i]);
		printf("%d\n",out[i]);
	}
	return 0;
}
