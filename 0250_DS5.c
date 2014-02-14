#include<stdio.h>
#include<time.h>
#include<stdlib.h>
long long int merge(long long int left[],long long int right[], long long int a[], int len, int lenl)
{
	int i=1,j=1,k=1;
	while(i<=lenl&&j<=(len-lenl))
	{
		if(left[i]<=right[j])
			a[k++]=left[i++];

		else
			a[k++]=right[j++];
	}
	while(i<=lenl)
		a[k++]=left[i++];
	while(j<=(len-lenl))
		a[k++]=right[j++];
}

void sort(long long int a[],int len)
{
	int i,j=1;
	if(len==1)
		return;
	else
	{
		int mid=len/2;
		long long int left[mid],right[len-mid];
		for(i=1;i<=mid;i++)
			*(left+i)=*(a+i);
		for(;i<=len;i++)
			*(right+(j++))=*(a+i);
		sort(left,mid);
		sort(right,len-mid);
		merge(left,right,a,len,mid);
	}
}
int main()
{
	srand(time(NULL));
	int n=500000,i;
	long long int a[n];
	for(i=1;i<=n;i++)
		a[i]=rand()%1000;
	sort(a,n);
	return 0;
}
