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
const LL base = 2 * (1e9 + 7);

inline LL f(LL n)
{
	return (n * (n - 1))/2;
}

inline LL hash_(LL x, LL y)
{
	return base * x + y;
}

int main()
{
	int __T;
	scanf("%d", &__T);
	unordered_map<LL, LL> X, Y, points;
	for (int t = 1; t <= __T; t++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		X[x]++;
		Y[y]++;
		points[hash_(x, y)]++;;
	}
	LL ans = 0;
	for (auto &x: X)
		ans += f(x.second);
	for (auto &y: Y)
		ans += f(y.second);
	for (auto &p: points)
		ans -= f(p.second);
	printf("%lld\n", ans);
	return 0;
}
