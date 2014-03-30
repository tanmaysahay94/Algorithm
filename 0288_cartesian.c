#include<stdio.h>
int bCount,cCount,preOrder[1000000],postOrder[1000000];
void cTree(int a[],int start,int end)
{
	if(start>end)
		return;
	int i,min=a[start],minIndex=start;
	for(i=start;i<=end;i++)
		if(a[i]<min)
		{
			min=a[i];
			minIndex=i;
		}
	preOrder[--cCount]=min;
	cTree(a,start,minIndex-1);
	cTree(a,minIndex+1,end);
	postOrder[--bCount]=min;
}
void print(int a[],int n)
{
	int i;
	for(i=n-1;i>0&&printf("%d ",a[i]);i--);
	printf("%d\n",a[i]);
}
int main()
{
	int i,n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		cCount=bCount=n;
		cTree(a,0,n-1);
		print(preOrder,n);
		print(postOrder,n);
	}
	return 0;
}
