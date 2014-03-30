#include<stdio.h>
#include<stdlib.h>
void shuffleUp(int a[],int size,int i)
{
	int left=2*i,right=2*i+1,minIndex=i;
	if(left<size&&a[left]<a[minIndex])
		minIndex=left;
	if(right<size&&a[right]<a[minIndex])
		minIndex=right;
	if(minIndex!=i)
	{
		a[i]=a[i]^a[minIndex]^(a[minIndex]=a[i]);
		shuffleUp(a,size,minIndex);
	}
}
void generateMinHeap(int a[],int size)
{
	int i;
	for(i=size/2;i>=0;i--)
		shuffleUp(a,size,i);
}
int kthLargest(int a[],int size,int k)
{
	int i,minHeap[k];
	for(i=0;i<k;i++)
		minHeap[i]=a[i];
	generateMinHeap(minHeap,k);
	for(i=k;i<size;i++)
	{
		if(a[i]>minHeap[0])
		{
			minHeap[0]=a[i];
			shuffleUp(minHeap,k,0);
		}
	}
	return minHeap[0];
}
int main()
{
	int a[500000],testTakers=0,qualified,numberOfQueries,query,input;
	scanf("%d",&numberOfQueries);
	while(numberOfQueries--)
	{
		scanf("%d",&query);
		if(query==1)
		{
			qualified=testTakers/4;
			if(!qualified)
				printf("-1\n");
			else
				printf("%d\n",kthLargest(a,testTakers,qualified));
		}
		else if(query==2)
			scanf("%d",&a[testTakers++]);
	}
	return 0;
}
