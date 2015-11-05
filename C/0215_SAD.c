#include<stdio.h>
int main()
{
	int r,c,a[200][200],loc,minRow,maxCol,i,j,k,f=0;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&a[i][j]);
	for(i=0;i<r;i++)
	{
		minRow=1000000001;
		for(j=0;j<c;j++)
			if(a[i][j]<minRow)
			{
				minRow=a[i][j];
				loc=j;
			}
		for(j=0;j<c;j++)
			if(a[i][j]==minRow)
			{
				for(k=0;k<r;k++)
				{
					if(a[k][j]>minRow)
					{
						f=1;
						break;
					}
				}
				if(k==r)
					goto a;
			}
	}
	printf("GUESS\n");
	return 0;
a:	{
		printf("%d\n",minRow);
		return 0;
	}
}
