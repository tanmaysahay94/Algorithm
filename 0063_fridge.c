#include<stdio.h>
int nFridge=0;
int fridge(int nIceCream,int maxIceCream)
{
	if(nIceCream<=maxIceCream)
	{
		nFridge++;
		return nFridge;
	}
	else
	{
		if(!(nIceCream%2))
		{
			fridge(nIceCream/2,maxIceCream);
			fridge(nIceCream/2,maxIceCream);
		}
		else
		{
			fridge(nIceCream/2,maxIceCream);
			fridge(nIceCream/2+1,maxIceCream);
		}
	}
}
int main()
{
	int T,N,K,i,j,output_count=0;
	int output[100500];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&N,&K);
		nFridge=0;
		printf("%d\n",fridge(N,K));
	}
	return 0;
}
