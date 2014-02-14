#include<stdio.h>
int main()
{
	int T,N,C,k,total;
	scanf("%d",&T);
	while(T--)
	{
		total=0;
		scanf("%d%d",&N,&C);
		int A[N];
		for(k=0;k<N;k++)
		{
			scanf("%d",&A[k]);
			total+=A[k];
		}
		if(C<total)
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}
