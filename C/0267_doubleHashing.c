#include<stdio.h>
void doubleHashInsert(int a[],int val,int size)
{
}
int doubleHashSearch(int a[],int val,int size)
{
}
int main()
{
	int k,i,toInput;
	printf("Table size: ");
	scanf("%d",&k);
	int a[k];
	for(i=0;i<k;i++)
	{
		scanf("%d",&toInput);
		doubleHashInsert(a,toInput,k);
	}
	printf("Search value: ");
	scanf("%d",&toInput);
	printf("If value is not found, -1 is printed.\nValue found at location %d\n",doubleHashSearch(a,toInput,k));
	return 0;
}
