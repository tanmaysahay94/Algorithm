#include<stdio.h>
int main()
{
	int test,nNote,cost,totalPay,i,min;
	scanf("%d",&test);
	while(test--)
	{
		int vNote[110]={0};
		totalPay=0;
		scanf("%d%d",&nNote,&cost);
		for(i=0;i<nNote;i++)
		{
			scanf("%d",&vNote[i]);
			totalPay+=vNote[i];
		}
		min=vNote[0];
		for(i=0;i<nNote;i++)
			if(vNote[i]<min)
				min=vNote[i];
		if(!totalPay%cost||totalPay%cost<min)
			printf("%d\n",totalPay/cost);
		else
			printf("-1\n");
	}
	return 0;
}
