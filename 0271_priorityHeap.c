#include<stdio.h>
int heap[1000000],other[1000000],currSize=1;				//location refers to the location where the number is input
void insertMin()
{
	int val,location,i,parent,done=0;
	printf("Enter value to insert\n");
	scanf("%d",&val);
	heap[currSize++]=val;
	location=currSize-1;
	parent=location/2;
	while(parent>=1&&!done)
	{
		if(heap[location]<heap[parent])
		{
			heap[location]=heap[location]^heap[parent]^(heap[parent]=heap[location]);
			location=parent;
			parent>>=1;
		}
		else
			done=1;
	}
}
void deleteMin()
{
	int done=0,lChild,rChild,parent=1,lastLeaf=currSize-1,smallerKid;
	printf("%d ",heap[1]);
	heap[1]=heap[lastLeaf];
	currSize--;
	if(lastLeaf==3)
	{
		if(heap[1]>heap[2])
			heap[1]=heap[1]^heap[2]^(heap[2]=heap[1]);
	}
	else
	{
		while(parent<=lastLeaf&&!done)
		{
			lChild=parent<<1;
			rChild=lChild+1;
			if(lChild>=lastLeaf||rChild>=lastLeaf)
				break;
			smallerKid=heap[lChild]<heap[rChild]?lChild:rChild;
			if(heap[parent]>heap[smallerKid])
			{
				heap[parent]=heap[parent]^heap[smallerKid]^(heap[smallerKid]=heap[parent]);
				parent=smallerKid;
			}
			else
				done=1;
		}
	}
}
void print()
{
	int i;
	for(i=1;i<currSize-1&&printf("%d ",heap[i]);i++);
	printf("%d\n",heap[i]);
}
int main()
{
	heap[0]=0;
	int choice,i,lim;
	char proceed;
	do
	{
		printf("1. InsertMin\n2. DeleteMin\n3. Print\n4. Heap Sort\nAny other number - Exit\nEnter your choice\n");
		scanf("%d",&choice);
		if(choice==1)
			insertMin();
		else if(choice==2)
		{
			deleteMin();
			printf("\n");
		}
		else if(choice==3)
			print();
		else if(choice==4)
		{
			lim=currSize;
			for(i=0;i<lim-1;i++)
				deleteMin();
			printf("\n");
		}
		else
			return 0;
		printf("Press (y/Y) to continue\n");
		scanf("%c%c",&proceed,&proceed);
	}while(proceed=='y'||proceed=='Y');
}
