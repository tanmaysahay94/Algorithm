#include<stdio.h>
int main()
{
	int i,j,k,Ar,Ac,Br,Bc,p,q;
	printf("Dimensions of Array A:");
	scanf("%d%d",&Ar,&Ac);
	printf("Dimensions of Array B:");
	scanf("%d%d",&Br,&Bc);
	int A[Ar][Ac],B[Br][Bc],C[Ar][Bc];
	if(Ac!=Br)
		printf("Multiplication not possible");
	else
	{
		printf("Elements of Array A\n");
		for(i=0;i<Ar;i++)
			for(j=0;j<Ac;j++)
				scanf("%d",&A[i][j]);
		printf("Elements of Array B\n");
		for(i=0;i<Br;i++)
			for(j=0;j<Bc;j++)
				scanf("%d",&B[i][j]);
		for(i=0;i<Ar;i++)
			for(j=0;j<Bc;j++)
				C[i][j]=0;
		for(i=0;i<Ar;i++)
			for(j=0;j<Bc;j++)
				for(k=0;k<Ac;k++)
					C[i][j]+=A[i][k]*B[k][j];
		printf("Elements of Array C\n");
		for(i=0;i<Ar;i++)
		{
			for(j=0;j<Bc;j++)
				printf("%d ",C[i][j]);
			printf("\n");
		}
	}
	return 0;
}
