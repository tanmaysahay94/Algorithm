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

typedef long long LL;

class DSU
{
	vector<int> parent, size;
	public:
	DSU(int n)
	{
		parent.resize(n);
		size.resize(n);
		for (int i = 0; i < n; i++)
			parent[i] = i, size[i] = 1;
	}
	int getSize(int i)
	{
		return size[(i)];
	}
	int getParent(int i)
	{
		if (i != parent[i])
			parent[i] = getParent(parent[i]);
		return parent[i];
	}
	void merge(int i, int j)
	{
		i = getParent(i);
		j = getParent(j);
		if (i == j)
			return;
		int n = getSize(i);
		int m = getSize(j);
		if (n < m)
			swap(i, j), swap(n, m);
		parent[j] = i;
		size[i] += size[j];
		size[j] = 0;
	}
};

int main()
{
	LL n, m;
	scanf("%lld%lld", &n, &m);
	DSU astronaut(n);
	for (LL i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		astronaut.merge(a, b);
	}
	vector<LL> v;
	for (int i = 0; i < n; i++)
	{
		trace(i, astronaut.getSize(i));
		if (astronaut.getSize(i))
			v.push_back(astronaut.getSize(i));
	}
	vector<LL> sufSum(v.size() + 1);
	for (int i = v.size() - 1; i >= 0; i--)
		sufSum[i] = sufSum[i + 1] + v[i];
	LL ans = 0;
	for (int i = 0; i < (int) v.size(); i++)
		ans += v[i] * sufSum[i + 1];
	printf("%lld\n", ans);
	/*
	   int __T;
	   scanf("%d", &__T);
	   for (int t = 1; t <= __T; t++)
	   {
	   }
	   */
	return 0;
}
