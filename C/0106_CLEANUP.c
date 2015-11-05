#include<stdio.h>
int main()
{
	int t,done,total,job[1050],i,work,cook[550],person,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&total,&done);
		for(i=1;i<=total;i++)
			job[i]=0;
		for(i=1;i<=done;i++)
		{
			scanf("%d",&work);
			job[work]=1;
		}
		for(i=1,person=1,count=0;i<=total;i++)
		{
			if(!job[i])
			{
				if(person&1)
					printf("%d ",i);
				else
				{
					cook[count]=i;
					count++;
				}
				person++;
			}
		}
		printf("\n");
		for(i=0;i<count;i++)
			printf("%d ",cook[i]);
		printf("\n");
	}
	return 0;
} 
