#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	//declaring single array
	int*a=(int*)malloc(sizeof(int)*n);

	//declaring double array
	int**b;
	b=(int**)malloc(sizeof(int*)*3);
	int i,j;
	for(i=0;i<3;i++)
		b[i]=(int*)malloc(sizeof(int)*4);
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			scanf("%d",&b[i][j]);
	for(i=0;i<3;i++)
		for(j=0;j<n;j++)
			printf("%d ",b[i][j]);
	return 0;
}
