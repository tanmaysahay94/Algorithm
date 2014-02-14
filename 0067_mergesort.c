#include <stdio.h>
long long int a[150000];
void merge(long long l[],long long r[],long long a[],int lL,int lR)
{
	int i,j,k;
	i=j=k=0;
	while(i<lL&&j<lR)
	{
		if(l[i]<=r[j])
			a[k++]=l[i++];
		else
			a[k++]=r[j++];
	}
	while(i<lL)
		a[k++]=l[i++];
	while(j<lR)
		a[k++]=r[j++];
}
long long sort(long long int P[],int size)
{
	int lenL,lenR,i;
	if(size>1)
	{
		lenL=size/2;
		lenR=size-lenL;
		long long int L[lenL],R[lenR];
		for(i=0;i<lenL;i++)
			*(L+i)=*(P+i);
		for(i=lenL;i<size;i++)
			*(R+i-lenL)=*(P+i);
		sort(L,lenL);
		sort(R,lenR);
		merge(L,R,P,lenL,lenR);
	}
	else
		return;
}
int main()
{
	int t,n,i;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lld",a+i);
		sort(a,n);
		for(i=0;i<n;i++)
			printf("%lld ",*(a+i));
		printf("\n");
	}
	return 0;
}
