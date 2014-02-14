#include<stdio.h>
#define MAX 10


int fnPlace(int iK,int iI,int iX[10])
{
	int iJ;
	for(iJ=1;iJ<=iK-1;iJ++)
	{
		if(iX[iJ]==iI||abs(iJ-iK)==abs(iX[iJ]-iI))
			return 0;
	}
	return 1;
}

void fnQueens(int iK,int iN)
{
	int iI,iJ,iL;
	static int iCount,iX[10];
	for(iI=1;iI<=iN;iI++)
	{
		if(fnPlace(iK,iI,iX))
		{
			iX[iK]=iI;
			if(iK==iN)
			{
				printf("\nSolutions are : ");
				for(iJ=1;iJ<=iN;iJ++)
					printf(" %d ",iX[iJ]);
			}
			else
				fnQueens(iK+1,iN);
		}
	}
}


int main()
{
	int iNo;
	printf("Enter the no of Queens : ");
	scanf("%d",&iNo);
	fnQueens(1,iNo);
	printf("\n");
	return 0;
}
