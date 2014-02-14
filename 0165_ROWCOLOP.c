#include<stdio.h>
#include<string.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,q,t,num,i,j;
	char p[10];
	scanf("%d%d",&n,&q);
	int map[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			map[i][j]=0;
	while(q--)
	{
		scanf("%s %d%d",p,&t,&num);
	}
	return 0;
}
