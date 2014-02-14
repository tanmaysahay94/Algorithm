#include<stdio.h>
int main()
{
	long long int T,a[501],lis[501],i,j,size,max;						//T-testcases,a=array,lis=longest increasing subseq,size-size of arr
	scanf("%lld",&T);
	while(T--)
	{       
		max=1;										//max at least 1. ALWAYS.
		scanf("%lld",&size);
		for(i=0;i<size;i++)
			scanf("%lld",&a[i]);
		lis[0]=1;
		for(i=1;i<size;i++)
		{
			lis[i]=1;
			for(j=i-1;j>=0;j--)
				if(a[j]<a[i]&&(lis[j]+1)>lis[i])
					lis[i]=lis[j]+1;
			max=lis[i]>max?lis[i]:max;
		}
		printf("%lld\n",max);
	}
	return 0;
}
