#include<stdio.h>
int main()
{
	int T,n,i,j;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		int a[n][n],b[n][n];
		for(i=0;i<n;i++)
			for(j=0;j<=i;j++)
				scanf("%d",&a[i][j]);
		for(j=0;j<n;j++)
			b[n-1][j]=a[n-1][j];
		for(i=n-1;i>0;i--)
			for(j=i;j>0;j--)
				b[i-1][j-1]=a[i-1][j-1]+(b[i][j]>b[i][j-1]?b[i][j]:b[i][j-1]);
		printf("%d\n",b[0][0]);
	}
	return 0;
} 
