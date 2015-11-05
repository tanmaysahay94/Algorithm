#include<stdio.h>
long long int cmp(const void *a,const void *b)
{
	return *(long long int*)a-*(long long int*)b;
}
//long long int memoizeSum[100500]={0};
unsigned long long int SumUpTo(unsigned long long int sahay)
{
	unsigned long long int i,sum=0;
	for(i=1;i<=sahay;i++)
		sum+=i;
	return sum;
/*	if(!memoizeSum[sahay])
	{
		if(sahay==1)
			memoizeSum[sahay]=1;
		else
			memoizeSum[sahay]=sahay+SumUpTo(sahay-1);
	}
	return memoizeSum[sahay];*/
}
int main()
{
	unsigned long long int T,N,nMinus,R,i,p,lawl[696969]={0};
	scanf("%llu",&T);
	while(T--)
	{
		scanf("%llu",&N);
		p=SumUpTo(N-1);
		for(i=0;i<N;i++)
			scanf("%llu",&lawl[i]);
		qsort(lawl,N,sizeof(long long int),cmp);
		nMinus=N-1;
		for(i=0;i<nMinus;i++)
			if(lawl[i]==lawl[i+1])
				p--;
		printf("%llu\n",p);
	}
	return 0;
}
