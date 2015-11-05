#include<stdio.h>
#include<limits.h>
int main()
{
	int i,max,A[10];
	for(i=0;i<10;i++)
		scanf("%d",&A[i]);
	max=INT_MIN;
	for(i=0;i<10;i++)
		if(max<A[i])
			max=A[i];
	printf("%d\n",max);
	return 0;
}
