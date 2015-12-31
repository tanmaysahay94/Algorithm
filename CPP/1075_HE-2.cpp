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

LL fastPow(LL a, LL b, LL mod)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

int main()
{
	int n;
	LL p;
	scanf("%d%lld", &n, &p);
	map<LL, LL> m;
	for (int i = 0; i < n; i++)
	{
		LL val;
		scanf("%lld", &val);
		val %= p;
		if (val == fastPow(val, p - 2, p)) continue;
		m[val]++;
	}
	LL ans = 0;
	unordered_set<LL> considered;
	for (auto mm: m)
	{
		if (considered.count(mm.first)) continue;
		LL inv = fastPow(mm.first, p - 2, p);
		considered.insert(mm.first);
		considered.insert(inv);
		ans += max(mm.second, m[inv]);
	}
	printf("%lld\n", ans);
	return 0;
}
