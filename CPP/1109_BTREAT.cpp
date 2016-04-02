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

const int maxn = 1e6 + 5;
LL C[maxn];

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		LL n;
		scanf("%lld", &n);
		LL sum = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &C[i]);
			sum += C[i];
		}
		if (sum % n)
		{
			printf("No Treat\n");
			continue;
		}
		sum /= n;
		LL ans = 0;
		for (int i = 0; i < n; i++)
			ans += (C[i] - sum) * (C[i] > sum);
		printf("%lld\n", ans);
	}
	return 0;
}
