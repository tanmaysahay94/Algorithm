#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

class BIT
{
	int n;
	vector<long long> v;
	public:
	BIT(int sz)
	{
		n = sz+1;
		v = vector<long long>(n, 0);
	}
	void add(int ind, int ele)	//1-indexed
	{
		if(v[ind]+ele < 0)
			return;
		for(int i=ind; i<n; i+=(i&(-i)))
			v[i] += ele;
	}
	LL get(int ind)
	{
		LL sum = 0;
		for(int i=ind; i>0; i-=(i&(-i)))
			sum += v[i];
		return sum;
	}
	LL get(int start, int end)
	{
		return get(end) - get(start-1);
	}
	void print()
	{
		for(int i=1; i<n; i++)
			printf("%lld ", get(i, i));
		cout<<endl;
	}
};

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int a[10010];
	for(int i=0; i<n; i++)
		scanf("%d", a+i);
	vector<BIT> bits(m, BIT(n));
	for(int i=0; i<n; i++)
		bits[a[i]%m].add(i+1, a[i]);
	int q; scanf("%d", &q);
	while(q--)
	{
		char Q[2];
		int l, r, mod;
		scanf("%s", Q);
		scanf("%d %d", &l, &r);
		if(Q[0] == '+')
		{
			bits[a[l-1]%m].add(l, -a[l-1]);
			a[l-1] += r;
			bits[a[l-1]%m].add(l, a[l-1]);
			cout<<a[l-1]<<endl;
		}
		else if(Q[0] == '-')
		{
			if(a[l-1] >= r)
			{
				bits[a[l-1]%m].add(l, -a[l-1]);
				a[l-1] -= r;
				bits[a[l-1]%m].add(l, a[l-1]);
			}
			cout<<a[l-1]<<endl;
		}
		else if(Q[0] == 's')
		{
			scanf("%d", &mod);
			cout<<bits[mod].get(l, r)<<endl;
		}
	}
	return 0;
}
