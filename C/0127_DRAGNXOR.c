#include<stdio.h>
#include<math.h>
int main()
{
	int t,n,a,b,cA,cB,cF,f,i,N,K;
	scanf("%d",&t);
	while(t--)
	{
		f=cA=cB=0;
		scanf("%d%d%d",&n,&a,&b);
		while(a)
		{
			if(a&1)
				++cA;				//no. of 1's in A
			a>>=1;
		}
		while(b)
		{
			if(b&1)
				++cB;				//no. of 1's in B
			b>>=1;
		}
		cF=cA+cB;					//total no. of 1's
		if(cF<n)
		{
			N=n-1;
			K=n-cF;
			for(i=N;i>=K;i--)
				f+=pow(2,i);
		}
		else
		{
			for(i=0;i<n;i++)
				f=(f<<1)+1;
			f>>=(cF-n);
			f<<=(cF-n);
		}
		printf("%d\n",f);
	}
	return 0;
}
