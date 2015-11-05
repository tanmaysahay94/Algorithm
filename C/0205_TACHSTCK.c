#include<stdio.h>
int c(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n,d,l[100100],i,p=0;
	scanf("%d%d",&n,&d);
	for(i=0;i<n;i++)
		scanf("%d",l+i);
	qsort(l,n,sizeof(int),c);
	i=0;
	while(i<n-1)
	{
		if(l[i+1]-l[i]<=d)
		{
			p++;
			i+=2;
		}
		else
			i++;
	}
	printf("%d\n",p);
	return 0;
}
