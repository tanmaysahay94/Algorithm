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
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

vector<LL> present(int(1e6) + 10, 0LL), low(int(1e6) + 10, 1e10), t(int(1e6) + 10);

int main()
{
	LL n, k;
	SLL(n); SLL(k);
	for (LL i = 0; i < n; i++)
	{
		SLL(t[i]);
		LL idx = min(i + 1, n - i);
		present[t[i]] = 1LL;
		low[t[i]] = min(low[t[i]], idx);
	}
	LL ans = 1e10;
	LL found = 0;
	for (LL i = 0; i < n; i++)
	{
		LL cur = t[i];
		LL sym = k - cur;
		if (present[sym] and cur != sym and cur < k)
		{
			LL timeTaken = max(low[cur], low[sym]);
			ans = min(ans, timeTaken);
			found = 1;
		}
	}
	if (found)
		printf("%lld\n", ans);
	else
		printf("-1\n");
	return 0;
}
