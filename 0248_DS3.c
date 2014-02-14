#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int c(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	srand(time(NULL));
	int i, n = 1000000;
	int a[n];
	for(i=0;i<n;i++)
		a[i]=rand()%1000;
	qsort(a,n,sizeof(int),c);
	return 0;
}
