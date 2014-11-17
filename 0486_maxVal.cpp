#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n;
	SLL(n);
	VLL a(n);
	for (LL i = 0; i < n; i++)
		SLL(a[i]);
	sortv(a);
	LL ans = 0;
	for (LL i = 0; i < n - 1; i++)
	{
		if (a[i] == 1 or (a[i] == a[i - 1] and i))
			continue;
		for (LL j = a[i] << 1; j <= a[n - 1] + a[i]; j += a[i])
		{
			VLL::iterator idx = lower_bound(a.begin(), a.end(), j);
			LL cur = *(idx - 1);
			ans = max(ans, cur % a[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
