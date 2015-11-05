#include<stdio.h>
int main()
{
	int t,n,i,iterate,free,index,u_lim;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			a[i]=0;
		if(n==1)
			printf("1\n");
		else
		{
			a[1]=1;
			index=1;
			for(i=2;i<=n;i++)
			{
				iterate=0;
				free=n+1-i;
				if(free<=i)
				{
					u_lim=i%free;
					while(1)
					{
						if(index>n-1)
							index=0;
						if(u_lim==iterate&&(!a[index]))
						{
							a[index]=i;
							break;
						}
						else if(!a[index])
							iterate++;
						index++;
					}
				}
				else
				{
					while(1)
					{
						if(index>n-1)
							index=0;
						if(i==iterate&&(!a[index]))
						{
							a[index]=iterate;
							break;
						}
						else if(!a[index])
							iterate++;
						index++;
					}
				}
			}
			for(i=0;i<n-1;i++)
				printf("%d ",a[i]);
			printf("%d\n",a[i]);
		}
	}
	return 0;
}
