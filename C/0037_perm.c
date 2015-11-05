#include <stdio.h>
void swap(int v[],int i,int j)
{
	int t;
	t=v[i];
	v[i]=v[j];
	v[j]=t;
}
void perm(int v[],int n,int i)						//generates permutations from i to n-1
{
	int j;
	if(i==n)							//print permutations when at end of the array
	{
		for(j=0;j<n;j++)
			printf("%d ",v[j]);
		printf("\n");
	} 
	else
		for (j=i;j<n;j++)					//if not at end of array, look for permutations
		{
   			swap(v,i,j);
			perm(v,n,i+1);
			swap(v,i,j);
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	int v[n],i;
	for(i=0;i<n;i++) 
		scanf("%d",&v[i]);
	printf("Permutations are:\n");
	perm(v,n,0);
	return 0;
}
