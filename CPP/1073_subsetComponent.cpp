#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
    cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
    const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
	__f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

class DSU
{
	vector<int> parent, size;
	int total;
	public:
	DSU(int n)
	{
		total = n;
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, size[i] = 1;
	}
	int getSize(int i)
	{
		return size[i];
	}
	int getParent(int i)
	{
		if (i != parent[i])
			parent[i] = getParent(parent[i]);
		return parent[i];
	}
	int getTotal()
	{
		return total;
	}
	void merge(int i, int j)
	{
		i = getParent(i);
		j = getParent(j);
		if (i == j)
			return;
		total--;
		if (getSize(i) < getSize(j))
			swap(i, j);
		parent[j] = i;
		size[i] += size[j];
		size[j] = 0;
	}
};

typedef unsigned long long ULL;

int n;
const int sz = 64;

DSU generate(ULL& val)
{
	DSU D(sz);
	int i = 0;
	for (; i < sz; i++)
		if ((val >> i) & 1ULL)
			break;
	for (int j = i + 1; j < sz; j++)
		if ((val >> j) & 1ULL)
			D.merge(i, j);
	return D;
}

void merge(DSU& D, DSU& E)
{
	for (int i = 0; i < sz; i++)
		D.merge(D.getParent(i), E.getParent(i));
}

int main()
{
	scanf("%d", &n);
	vector<ULL> v(n);
	for (int i = 0; i < n; i++)
		scanf("%llu", &v[i]);
	vector<DSU> D(n, sz);
	for (int i = 0; i < n; i++)
		D[i] = generate(v[i]);
	int lim = 1 << n;
	ULL ans = 0;
	for (int mask = 0; mask < lim; mask++)
	{
		DSU tmp(sz);
		for (int bit = 0; bit < n; bit++)
			if ((mask >> bit) & 1ULL)
				merge(tmp, D[bit]);
		ans += tmp.getTotal();
	}
	printf("%llu\n", ans);
	return 0;
}
