#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
void sort(long long int Arr[],long long int,long long int);
int main()
{
	int kids,packets,i;
	scanf("%d",&packets);
	scanf("%d",&kids);
	long long int candy[packets];
	for(i=0;i<packets;++i)
		scanf("%lld",candy+i);
	sort(candy,0,packets-1);
	long long int w,u=2147483000;
	int k=packets-kids;
	for(i=0;i<=k;++i)
	{
		w=candy[i+kids-1]-candy[i];
		u=u<w?u:w;
	}
	printf("%lld\n",u);
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
