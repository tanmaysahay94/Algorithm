#include<stdio.h>
int high[1000000],low[1000000],highCount,lowCount;
void insertMin(int val)
{
	highCount++;
	high[highCount]=val;
	int now=highCount;
	while(high[now/2]>val)
	{
		high[now]=high[now/2];
		now/=2;
	}
	high[now]=val;
}
void insertMax(int val)
{
	lowCount++;
	low[lowCount]=val;
	int now=lowCount;
	while(low[now/2]<val)
	{
		low[now]=low[now/2];
		now/=2;
	}
	low[now]=val;
}
int deleteMin()
{
		int minElement,lastElement,child,now;
		minElement=high[1];
		lastElement=high[highCount--];
		for(now=1;now*2<=highCount;now=child)
		{
			child=now*2;
			if(child!=highCount&&high[child+1]<high[child])
				child++;
			if(lastElement>high[child])
				high[now]=high[child];
			else
				break;
		}
		high[now]=lastElement;
		return minElement;
}
int deleteMax()
{
	int maxElement,lastElement,child,now;
	maxElement=low[1];
	lastElement=low[lowCount--];
	for(now=1;now*2<=lowCount;now=child)
	{
		child=now*2;
		if(child!=lowCount&&low[child+1]>low[child])
			child++;
		if(lastElement<low[child])
			low[now]=low[child];
		else
			break;
	}
	low[now]=lastElement;
	return maxElement;
}
int main()
{
	highCount=lowCount=0;
	high[0]=-2147483648;
	low[0]=2147483647;
	int n,query,num,total=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&query);
		if(query==1)
		{
			if(total/4)
				printf("%d\n",high[1]);
			else
				printf("-1\n");
		}
		else if(query==2)
		{
			scanf("%d",&num);
			total++;
			if(total<=3)
				insertMax(num);
			else if(total%4==0)
			{
				if(num>=low[1])
					insertMin(num);
				else
				{
					insertMin(deleteMax());
					insertMax(num);
				}
			}
			else
			{
				if(num>=high[1])
				{
					insertMax(deleteMin());
					insertMin(num);
				}
				else
					insertMax(num);
			}
		}
	}
	return 0;
}
