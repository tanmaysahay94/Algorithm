#include<stdio.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int c(int a,int b)
{
	if(a==b||!b)
		return 1;
	else
		return c(a-1,b)+c(a-1,b-1);
}
int main()
{
	int t,bestN,check,i,p[11],countF,countL;
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<11;i++)
			scanf("%d",&p[i]);
		qsort(p,11,sizeof(int),cmp);
		scanf("%d",&bestN);
		check=11-bestN;
		countF=countL=0;
		for(i=0;i<check;i++)
			if(*(p+i)==*(p+check))
				countF++;
		for(i=check;i<11;i++)
			if(*(p+i)==*(p+check))
				countL++;
		countF+=countL;
		printf("%d\n",c(countF,countL));
	}
	return 0;
}
