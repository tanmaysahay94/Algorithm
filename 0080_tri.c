#include<stdio.h>
typedef struct point{
	int x,y;
}p;
typedef struct triangle{
	p pt[3];
}t;
int main()
{
	t test;
	int i;
	for(i=0;i<3;++i)
	{
		printf("Input x coordinate of point %d:",i+1);
		scanf("%d",&test.pt[i].x);
		printf("Input y coordinate of point %d:",i+1);
		scanf("%d",&test.pt[i].y);
	}
        if((test.pt[2].y-test.pt[1].y)*(test.pt[1].x-test.pt[0].x)==(test.pt[2].x-test.pt[1].x)*(test.pt[1].y-test.pt[0].y))
		printf("Triangle not possible.\n");
	else
		printf("Triangle is possible.\n");
	return 0;
}
