#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,total=0;
		scanf("%d",&n);
		char bomb[1001];
		int exists[1000];
		scanf("%s",bomb);
		for(i=0;i<n;i++)
			exists[i]=1;
		for(i=0;i<n;i++)
		{
			if(bomb[i]=='1')
			{
				if(i==0)
				{
					total+=exists[0];
					if(n>1)
						total+=exists[1];
					exists[0]=exists[1]=0;
				}
				else if(i==n-1)
				{
					total+=exists[n-1]+exists[n-2];
					exists[n-1]=exists[n-2]=0;
				}
				else
				{
					total+=exists[i]+exists[i-1]+exists[i+1];
					exists[i]=exists[i+1]=exists[i-1]=0;
				}
			}
		}
		printf("%d\n",n-total);
	}
	return 0;
} 
