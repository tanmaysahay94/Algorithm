#include<stdio.h>
typedef struct chef
{
	unsigned long long int age,skill;
}chef;
chef min[100010],max[100010];	//min-old heap, max-young heap
unsigned long long int minCount,maxCount;
void insertMin(chef c)
{
	minCount++;
	min[minCount]=c;
	int now=minCount;
	while(min[now/2].age>c.age)
	{
		min[now]=min[now/2];
		now/=2;
	}
	min[now]=c;
}
void insertMax(chef c)
{
	maxCount++;
	max[maxCount]=c;
	int now=maxCount;
	while(max[now/2].age<c.age)
	{
		max[now]=max[now/2];
		now/=2;
	}
	max[now]=c;
}
chef deleteMin()
{
	chef minElement,lastElement;
	int child,now;
	minElement=min[1];
	lastElement=min[minCount--];
	for(now=1;now*2<=minCount;now=child)
	{
		child=now*2;
		if(child!=minCount&&min[child+1].age<min[child].age)
			child++;
		if(lastElement.age>min[child].age)
			min[now]=min[child];
		else
			break;
	}
	min[now]=lastElement;
	return minElement;
}
chef deleteMax()
{
	chef maxElement,lastElement;
	int child,now;
	maxElement=max[1];
	lastElement=max[maxCount--];
	for(now=1;now*2<=maxCount;now=child)
	{
		printf("o");
		child=now*2;
		if(child!=maxCount&&max[child+1].age>max[child].age)
			child++;
		if(lastElement.age<max[child].age)
			max[now]=max[child];
		else
			break;
	}
	max[now]=lastElement;
	return maxElement;
}
int main()
{
	chef c,swap;
	min[0].age=-2147483648;
	max[0].age=2147483648;
	unsigned long long int diff,i,n,skillOld,skillYoung;
	minCount=maxCount=skillOld=skillYoung=0;
	scanf("%llu",&n);
	for(i=0;i<n;i++)
	{
		scanf("%llu%llu",&c.age,&c.skill);
		if(i==0)
		{
			insertMax(c);
			skillYoung+=c.skill;
		}
		else if(i&1)	//add to old heap
		{
			if(c.age<max[1].age)
			{
				swap=deleteMax();
				insertMin(swap);
				insertMax(c);
				skillYoung=skillYoung-swap.skill+c.skill;
				skillOld=skillOld+swap.skill;
			}
			else
			{
				insertMin(c);
				skillOld=skillOld+c.skill;
			}
		}
		else			//add to young heap
		{
			if(c.age>min[1].age)
			{
				swap=deleteMin();
				insertMax(swap);
				insertMin(c);
				skillOld=skillOld-swap.skill+c.skill;
				skillYoung=skillYoung+swap.skill;
			}
			else
			{
				insertMax(c);
				skillYoung=skillYoung+c.skill;
			}
		}
		diff=skillYoung-skillOld;
		printf("%llu\n",diff>=0?diff:-diff);
	}
	return 0;
}
