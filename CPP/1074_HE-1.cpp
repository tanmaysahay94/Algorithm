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
const LL lo = 1;
const LL hi = 1000;
LL ans[3005];

LL g(LL n)
{
	LL left = 1;
	while (n - left > hi) left++;
	LL right = 1000;
	while (n - right< lo)right--;
	return right - left + 1;
}

LL f(LL n)
{
	LL ret = 0;
	LL left = 1;
	while (n - left > 2 * hi) left++;
	LL right = 1000;
	while (n - right < 2 *lo)right--;
	for (LL i = left; i <= right; i++) ret += g(n - i);
	return ret;
}

int main()
{
	memset(ans, 0, sizeof(ans));
	for (int i = 3; i <= 3000; i++)
		ans[i] = f((LL)i);
	for (int i = 3000; i >= 3; i--)
		ans[i] += ans[i + 1];
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int v;
		scanf("%d", &v);
		printf("%lld\n", ans[v]);
	}
	return 0;
}
