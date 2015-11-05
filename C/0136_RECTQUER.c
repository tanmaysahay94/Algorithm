#include<stdio.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,i,j,q,x1,y1,x2,y2,count,out,map[300][300],checkArr[90090];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&map[i][j]);
	scanf("%d",&q);
	while(q--)
	{
		out=1;
		count=0;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		for(i=x1-1;i<x2;i++)
			for(j=y1-1;j<y2;j++)
				checkArr[count++]=map[i][j];
		qsort(checkArr,count,sizeof(int),cmp);
		for(i=0;i<count-1;i++)
			if(checkArr[i]!=checkArr[i+1])
				out++;
		printf("%d\n",out);
	}
	return 0;
}
