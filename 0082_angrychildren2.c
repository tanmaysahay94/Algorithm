#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int cmp(const void*a,const void*b)
{
	return (*(long long int*)a-*(long long int*)b);
}
int main()
{
	int kids,packets,i,j,k,l,m,c;
	scanf("%d",&packets);
	scanf("%d",&kids);
	long long int candy[packets],u,min=2147483967;
	for(i=0;i<packets;++i)
		scanf("%lld",candy+i);
	qsort(candy,packets,sizeof(long long int),cmp);
	c=packets-kids;
	for(i=0;i<=c;i++)
	{
		u=0;
		m=i+kids;
		l=m-1;
		for(j=i;j<l;j++)
			for(k=j+1;k<m;k++)
				u+=candy[k]-candy[j];
		if(u<min)
			min=u;
	}
	printf("%lld\n",min);
}
