#include<stdio.h>
int main()
{
	int t,l,c,x,y;
	char move[15];
	scanf("%d",&t);
	gets(move);
	while(t--)
	{
		gets(move);
		if((move[0]>='a'&&move[0]<='h')&&(move[1]>='1'&&move[1]<='8')&&(move[2]=='-')&&(move[3]>='a'&&move[3]<='h')&&(move[4]>='1'&&move[4]<='8')&&(move[5]=='\0'))
		{
			x=move[3]-move[0];
			y=move[4]-move[1];
			if(x<0)
				x*=-1;
			if(y<0)
				y*=-1;
			if(x+y==3)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("Error\n");
	}
	return 0;
}
