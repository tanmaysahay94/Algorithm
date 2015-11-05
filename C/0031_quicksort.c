#include<stdio.h>
void sort(long long int Arr[],long long int,long long int);
int main()
{
	long long int T,n,i,c;
	scanf("%lld",&T);
	while(T--)
	{
		c=0;
		scanf("%lld",&n);
		long long int A[n];
		for(i=0;i<n;i++)
			scanf("%lld",&A[i]);
		sort(A,0,n-1);
		for(i=0;i<n;i++)
			printf("%lld ",A[i]);
		printf("\n");
	}
	return 0;
}
void sort(long long int Arr[],long long int initial,long long int final)
{
	long long int i,j,fix;
	long long int temp;
	if(initial<final)
	{
		fix=initial;
		i=initial;
		j=final;
		while(i<j)
		{
			while(Arr[i]<=Arr[fix] && i<final)
				i++;
			while(Arr[j]>Arr[fix])
				j--;
			if(i<j)
			{
				temp=Arr[i];
				Arr[i]=Arr[j];
				Arr[j]=temp;
			}
		}
		temp=Arr[fix];
		Arr[fix]=Arr[j];
		Arr[j]=temp;
		sort(Arr,initial,j-1);
		sort(Arr,j+1,final);
	}
}
