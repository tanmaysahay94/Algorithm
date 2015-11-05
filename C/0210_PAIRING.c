#include<stdio.h>
int c(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,n,p,picked[20000],j,pair[20000][2],out[20000],i,count;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d%d",&n,&p);
		for(i=0;i<n;i++)
			picked[i]=0;
		for(i=0;i<p;i++)
			scanf("%d%d",&pair[i][0],&pair[i][1]);
		for(i=p-1;i>=0;i--)
		{
			if(!picked[pair[i][0]]&&!picked[pair[i][1]])
			{
				out[count++]=i;
				picked[pair[i][0]]=picked[pair[i][1]]=1;
			}
			if(count==n/2)
				break;
		}
		qsort(out,count,sizeof(int),c);
		for(i=0;i<count-1;i++)
			printf("%d ",out[i]);
		printf("%d\n",out[i]);
	}
	return 0;
}
