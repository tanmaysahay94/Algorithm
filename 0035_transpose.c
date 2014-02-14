#include<stdio.h>
int main()
{
	int szm,szn,i,j;
	printf("Size of the matrix:");
	scanf("%d%d",&szm,&szn);
	int A[szm][szn],B[szn][szm];
	for(i=0;i<szm;i++)
		for(j=0;j<szn;j++)
		{
			scanf("%d",&A[i][j]);
			B[j][i]=A[i][j];
		}
	for(i=0;i<szn;i++)
	{
		for(j=0;j<szm;j++)
			printf("%d ",B[i][j]);
		printf("\n");
	}
	return 0;
}
