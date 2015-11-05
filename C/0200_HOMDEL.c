#include<stdio.h>
int main() 
{
	int n,d[250][250],r,M,i,j,k,S,G,D,alternate;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&d[i][j]);
	for(i=0;i<n;i++) 
		for(j=0;j<n;j++)
			for(k=0;k<n;k++)			// Warshall Algorithm for the shortest path
			{
				alternate=d[j][i]+d[i][k];
				if(alternate<d[j][k])
					d[j][k]=alternate;
			}
	scanf("%d",&M);
	while(M--) 
	{
		scanf("%d%d%d",&S,&G,&D);
		r=d[S][G]+d[G][D];
		printf("%d %d\n",r,r-d[S][D]);
	}
	return 0;
}
