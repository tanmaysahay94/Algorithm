#include<stdio.h>
int main()
{
	unsigned long long int max=0,p,a[20][20],i,j;
	for(i=0;i<20;i++)
		for(j=0;j<20;j++)
			scanf("%llu",&a[i][j]);
	//horizontal products
	for(i=0;i<20;i++)
		for(j=0;j<=16;j++)
		{
			p=1;
			p*=a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
			max=max>p?max:p;
		}
	//vertical products
	for(i=0;i<20;i++)
		for(j=0;j<=16;j++)
		{
			p=1;
			p*=a[j][i]*a[j+1][i]*a[j+2][i]*a[j+3][i];
			max=max>p?max:p;
		}
	//left diagonal products
	for(i=0;i<=16;i++)
		for(j=0;j<=16;j++)
		{
			p=1;
			p*=a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
			max=max>p?max:p;
		}
	//right diagonal products
	for(i=0;i<=16;i++)
		for(j=3;j<20;j++)
		{
			p=1;
			p*=a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3];
			max=max>p?max:p;
		}
	printf("%llu\n",max);
	return 0;
}
