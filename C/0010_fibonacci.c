#include<stdio.h>    
int main()  
{  
	long long unsigned n,Tn,i,f,fLast,j;

	scanf("%llu",&i);
	for(;i>0;i--)
	{    
		scanf("%llu",&n);  
		if(n>=0)  
		{ 
			f=1,fLast=1,j;
			if(n==0||n==1)
				Tn=1;
			for(j=2;j<=n;j++)
			{
				f=fLast+f;
				fLast=f-fLast;
			}
			Tn=f;
			printf("%llu\n",Tn);
		}
	}  
	return 0;  
}  

