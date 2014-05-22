#include<stdio.h>
long long tree[3000000]={0};
long long freq(long long idx)
{
	long long f=0;
	while(idx>0)
	{
		f+=tree[idx];
		idx-=(idx&-idx);
	}
	return f;
}
void update(long long idx,long long val)
{
	while(idx<3000000)
	{
		tree[idx]+=val;
		idx+=(idx&-idx);
	}
}
int main()
{
	long long n,q,i,v,idx;
	scanf("%lld%lld",&n,&q);
	char ch[3];
	for(i=0;i<n;i++)
	{
		scanf("%lld",&v);
		update(i+1,v);
	}
	while(q--)
	{
		scanf("%s%lld%lld",ch,&idx,&v);
		if(*ch=='S')
			printf("%lld\n",freq(v+1)-freq(idx));
		else if(*ch=='T')
			update(idx+1,-v);
		else
			update(idx+1,v);
	}
	return 0;
}
