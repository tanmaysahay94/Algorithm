#include<stdio.h>
int line(int x1,int y1,int x2,int y2,int x3,int y3)
{
	int c1,flag=0;
	c1=(y3-y1)*(x2-x1)-(x3-x1)*(y2-y1);
	if (!c1)
	{
		if(!((x2>=x1)&&(x3>=x1)&&(x3<=x2) || (x1>=x2)&&(x3>=x2)&&(x3<=x1)))
			return 0;
		if(!((y2>=y1)&&(y3>=y1)&&(y3<=y2) || (y1>=y2)&&(y3>=y2)&&(y3<=y1)))
			return 0;
		return 1;
	}
	else
		return 0;
}
int main()
{
	int N,x1,x2,x3,x4,y1,y2,y3,y4,c1,c2,c3,c4;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		c1=(y3-y1)*(x2-x1)-(x3-x1)*(y2-y1);//1,2/3
		c2=(y4-y1)*(x2-x1)-(x4-x1)*(y2-y1);//1,2/4
		c3=(y1-y3)*(x4-x3)-(x1-x3)*(y4-y3);//3,4/1
		c4=(y2-y3)*(x4-x3)-(x2-x3)*(y4-y3);//3,4/2
		if(line(x1,y1,x2,y2,x3,y3)||line(x1,y1,x2,y2,x4,y4)||line(x3,y3,x4,y4,x1,y1)||line(x3,y3,x4,y4,x2,y2))
			printf("YES\n");
		else if((c1*c2<0)&&(c3*c4<0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
