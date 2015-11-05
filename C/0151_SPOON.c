#include<stdio.h>
int main()
{
	int t,r,c,i,j,found;
	char a[100][100],d;
	scanf("%d",&t);
	while(t--)
	{
		found=0;
		scanf("%d%d",&r,&c);
		for(i=0;i<r;i++)
		{
			scanf("%c",&d);
			for(j=0;j<c;j++)
				scanf("%c",&a[i][j]);
		}
		if(c>=5)
		{
			for(i=0;i<r;i++)
			{
				for(j=0;j<=c-5;j++)
					if((a[i][j]=='s'||a[i][j]=='S')&&(a[i][j+1]=='p'||a[i][j+1]=='P')&&(a[i][j+2]=='o'||a[i][j+2]=='O')&&(a[i][j+3]=='o'||a[i][j+3]=='O')&&(a[i][j+4]=='n'||a[i][j+4]=='N'))
					{
						found=1;
						break;
					}
				if(found)
					break;
			}
		}
		if(!found)
		{
			if(r>=5)
			{
				for(i=0;i<c;i++)
				{
					for(j=0;j<=r-5;j++)
						if((a[j][i]=='s'||a[j][i]=='S')&&(a[j+1][i]=='p'||a[j+1][i]=='P')&&(a[j+2][i]=='o'||a[j+2][i]=='O')&&(a[j+3][i]=='o'||a[j+3][i]=='O')&&(a[j+4][i]=='n'||a[j+4][i]=='N'))
						{
							found=1;
							break;
						}
					if(found)
						break;
				}
			}
		}
		if(found)
			printf("There is a spoon!\n");
		else
			printf("There is indeed no spoon!\n");
	}
	return 0;
}
