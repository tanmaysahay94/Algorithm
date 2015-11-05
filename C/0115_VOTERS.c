#include<stdio.h>
int main()
{
	int n,a[1010],visit[1010],output[1010][1010],cycleLength[1010],i,j,start,current,end,index=0,indexEle=0;
	scanf("%d",&n);
	a[0]=0;
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=0;i<1010;i++)
		visit[i]=0;
	for(i=1;i<=n;i++)
	{
		if(!visit[i])
		{
			visit[i]=1;
			start=current=i;
			output[index][indexEle++]=start;
			end=-42;
			while(start!=end)
			{
				end=a[current];
				visit[current]=1;
				output[index][indexEle++]=current=end;
			}
			cycleLength[index]=indexEle;
			index++;
			indexEle=0;
		}
	}
	printf("%d\n",index);
	for(i=0;i<index;i++)
	{
		for(j=0;j<cycleLength[i]-1;j++)
			printf("%d ",output[i][j]);
		printf("%d\n",output[i][j]);
	}
	return 0;
} 
