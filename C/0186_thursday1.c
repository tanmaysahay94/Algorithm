#include<stdio.h>
#include<math.h>
int main()
{
	int t,x,y,x1,x2,y1,y2;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&x,&y);
		if(x>=0&&y>=0)
		{
			x1=y2=0;
			y1=x2=x+y;
		}
		else if(x>=0&&y<0)
		{
			x1=y2=0;
			y1=-(x+abs(y));
			x2=-y1;
		}
		else if(x<0&&y>=0)
		{
			x1=-(abs(x)+y);
			y2=-x1;
			x2=y1=0;
		}
		else
		{
			y1=x2=0;
			y2=x1=x+y;
		}
		printf("%d %d %d %d\n",x1,y1,x2,y2);
	}
	return 0;
}
