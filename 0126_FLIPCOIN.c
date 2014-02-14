#include<stdio.h>
int main()
{
	int n,q,qType,qStart,qEnd,headCount,i;
	scanf("%d%d",&n,&q);
	int coin[100000]={0};
	while(q--)
	{
		headCount=0;
		scanf("%d%d%d",&qType,&qStart,&qEnd);
		if(qType)
		{
			for(i=qStart;i<=qEnd;i++)
				if(coin[i])
					++headCount;
			printf("%d\n",headCount);
		}
		else
			for(i=qStart;i<=qEnd;i++)
				coin[i]=!coin[i];
	}
	return 0;
}
