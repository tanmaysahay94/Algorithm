#include<stdio.h>
#include<math.h>
void show(long long t[],long long size)
{
	long i;
	for(i=0;i<size-1&&printf("%lld ",t[i]);i++);
	printf("%lld\n",t[i]);
}
int main()
{
	long long n,k,i,otherMax=-(pow(10,9)+9),max=-(pow(10,9)+9);
	scanf("%lld%lld",&n,&k);
	long long a[n],b[n];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		max=max>a[i]?max:a[i];
	}
	if(k)
	{
		for(i=0;i<n;i++)
		{
			b[i]=max-a[i];
			otherMax=otherMax>b[i]?otherMax:b[i];
		}
		for(i=0;i<n;i++)
			a[i]=otherMax-b[i];
		if(k&1)
			show(b,n);
		else
			show(a,n);
	}
	else
		show(a,n);
	return 0;
}
