#include<stdio.h>
#include<string.h>
int main()
{
	int i,n,q,loc,val,rMax=0,cMax=0;
	int row[500000]={0};
	int col[500000]={0};
	char inst[20];
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%s%d%d",inst,&loc,&val);
		if(!strcmp(inst,"RowAdd"))
			row[loc-1]+=val;
		else if(!strcmp(inst,"ColAdd"))
			col[loc-1]+=val;
	}
	for(i=0;i<n;i++)
	{
		rMax=rMax>row[i]?rMax:row[i];
		cMax=cMax>col[i]?cMax:col[i];
	}
	printf("%d\n",rMax+cMax);
	return 0;
}
