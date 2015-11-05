#include<stdio.h>
int issafe(int a[][8],int,int,int);
int solve(int a[][8],int col,int n)
{
	int i;
	if (col==n)
		return 1;
	for(i=0;i<n;i++)
		if(issafe(a,i,col,n))
		{
			a[i][col]=1;
			if(solve(a,col+1,n))
				return 1;
			a[i][col]=0;
		}
	return 0;
}
int issafe(int a[][8],int row,int col,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if((i!=row)&&(j!=col))
			{
				if(a[row][j]==1||a[i][col]==1)			//check rows and columns
					return 0;
				if((i+j)==(row+col)&&(a[i][j]==1))		//check diagonals
					return 0;
				if(i>=j)
				{
					if(((i-j)==(row-col)&&(a[i][j])))
						return 0;
				}
				if(j>i)
				{
					if(((j-i)==(col-row)&&(a[i][j])))
						return 0;
				}
			}
		}
	}
	return 1;
}
int main()
{
	int i,j,n;
	scanf("%d",&n);
	int b[8][8];
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			b[i][j]=0;
	int flag=solve(b,0,n);
	if(flag)
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d ",b[i][j]);
			printf("\n");
		}
	return 0;
}
