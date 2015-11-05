#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i,j,pi,pj,bi,bj;
	char map[n][n];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		{
			scanf("%c",&map[i][j]);
			if(map[i][j]=='p')
			{
				pi=i;
				pj=j;
			}
			if(map[i][j]=='m')
			{
				bi=i;
				bj=j;
			}
		}
	if(bi>pi)
		for(i=0;i<bi-pi;i++)
			printf("UP\n");
	else
		for(i=0;i<pi-bi;i++)
			printf("DOWN\n");
	if(bj>pj)
		for(i=0;i<bj-pj;i++)
			printf("LEFT\n");
	else
		for(i=0;i<pj-bj;i++)
			printf("RIGHT\n");
	return 0;
}
