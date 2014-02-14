#include<stdio.h>
int main()
{
	int N,flag;
	double x1,y1,x2,y2,x3,y3,x4,y4,c1,c2;
	scanf("%d",&N);
	while(N>0)
	{
		scanf("%lf%lf",&x1,&y1);
		scanf("%lf%lf",&x2,&y2);
		scanf("%lf%lf",&x3,&y3);
		scanf("%lf%lf",&x4,&y4);
		flag=0;
		c1=x4*(y2-y1)+y4*(x1-x2)-x1*y2+x2*y1;
		c2=x3*(y2-y1)+y3*(x1-x2)-x1*y2+x2*y1;
		if((c1>=0&&c2>=0)||(c1<=0&&c2<=0))
		{
			c1=x4*(y3-y2)+y4*(x2-x3)-x2*y3+x3*y2;
			c2=x1*(y3-y2)+y1*(x2-x3)-x2*y3+x3*y2;
			if((c1>=0&&c2>=0)||(c1<=0&&c2<=0))
			{
				c1=x4*(y1-y3)+y4*(x3-x1)-x3*y1+x1*y3;
				c2=x2*(y1-y3)+y2*(x3-x1)-x3*y1+x1*y3;
				if((c1>=0&&c2>=0)||(c1<=0&&c2<=0))
					flag=1;
			}
		}
		if(flag==1)
			printf("YES\n");
		else
			printf("NO\n");
		N--;
	}
	return 0;
}
