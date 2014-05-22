#include<stdio.h>
int main()
{
	int n,i,j,ci,cj;
	scanf("%d",&n);
	while(n--)
	{
		ci=cj=0;
		scanf("%d%d",&i,&j);
		while(i-j)
		{
			if(i>j)
			{
				i>>=1;
				ci++;
			}
			else
			{
				j>>=1;
				cj++;
			}
		}
		printf("%d\n",ci+cj);
	}
	return 0;
}
