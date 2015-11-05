#include<stdio.h>
int main()
{
	int t,p,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&p);
		if(p>2048)
		{
			count=p/2048;
			p%=(int)2048;
		}
		else
			count=0;
		while(p)
		{
			if(p&1)
				count++;
			p>>=1;
		}
		printf("%d\n",count);
	}
	return 0;
} 
