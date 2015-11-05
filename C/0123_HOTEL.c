#include<stdio.h>
typedef struct g
{
	int time,check;
}g;
int cmp(const void *a,const void *b)
{
	if((*(g*)a).time==(*(g*)b).time)
		return (*(g*)a).check-(*(g*)b).check;
	return (*(g*)a).time-(*(g*)b).time;
}
int main()
{
	int t,n,i,l,cur,max;
	g gg[10010];
	scanf("%d",&t);
	while(t--)
	{
		cur=max=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&gg[i].time);
			gg[i].check=1;
		}
		l=2*n;
		for(i=n;i<l;i++)
		{
			scanf("%d",&gg[i].time);
			gg[i].check=0;
		}
		qsort(gg,l,sizeof(g),cmp);
		for(i=0;i<l;i++)
		{
			if(gg[i].check)
			{
				++cur;
				max=cur>max?cur:max;
			}
			else
				--cur;
		}
		printf("%d\n",max);
	}
	return 0;
}
