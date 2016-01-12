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

vector<LL> B, pre;

LL sumTo(LL n)
{
	return (n * (n + 1)) >> 1;
}

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		LL N, P;
		scanf("%lld%lld", &N, &P);
		B = vector<LL> (N);
		pre = vector<LL> (N+1);
		for (int i = 0; i < N; i++)
		{
			scanf("%lld", &B[i]);
			pre[i + 1] = pre[i] + B[i];
		}
		LL ans = 0;
		LL e = -1;
		for (int i = 1; i <= N; i++)
		{
			if (B[i - 1] > P) continue;
			int j = upper_bound(pre.begin() + i, pre.end(), pre[i - 1] + P) - pre.begin() - 1;
			if (e == j) continue;
			ans += sumTo(j - i + 1);
			if (i <= e) ans -= sumTo(e - i + 1);
			e = j;
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
