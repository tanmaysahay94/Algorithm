#include<stdio.h>
int cmp(void const *a, void const *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int t,i;
	scanf("%d",&t);
	int a[t];
	for(i=0;i<t;i++)
		scanf("%d",a+i);
	qsort(a,t,sizeof(int),cmp);
	for(i=0;i<t;i++)
		printf("%d\n",a[i]);
	return 0;
}
