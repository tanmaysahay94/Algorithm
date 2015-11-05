#include<stdio.h>
int main()
{
	int t,i,j,not_fix;
	char c[8][8];
	scanf("%d",&t);
	while(t--)
	{
		getchar();
		not_fix=0;
		for(i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
				c[i][j]=getchar();
			getchar();
		}
		for(i=0;i<8;i++)
		{
			if(c[i][0]==c[i][7])
			{
				not_fix=1;
				break;
			}
			else
			{
				for(j=0;j<7;j++)
					if(c[i][j]==c[i][j+1])
					{
						not_fix=1;
						break;
					}
				if(not_fix)
					break;
			}
		}
		if(not_fix)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
