#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 19;
const int mlim = 1 << maxn;

LL DP[mlim][maxn];

int main()
{
	memset(DP, 0, sizeof(DP));
	LL n, m, k;
	scanf("%lld%lld%lld", &n, &m, &k);
	vector<LL> a(n);
	LL c[20][20];
	memset(c, 0, sizeof(c));
	for (int i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	for (int i = 0; i < k; i++)
	{
		LL from, to, sat;
		scanf("%lld%lld%lld", &from, &to, &sat);
		c[--from][--to] = sat;
	}
	LL lim = 1 << n;
	LL ans = 0;
	for (int mask = 0; mask < lim; mask++)
	{
		int bcount = __builtin_popcount(mask);
		for (int to = 0; to < n; to++)
		{
			if (not (mask & (1 << to)))
				continue;
			DP[mask][to] = a[to];
			for (int from = 0; from < n; from++)
			{
				if (not (mask & (1 << from)))
					continue;
				if (from == to)
					continue;
				DP[mask][to] = max(DP[mask][to], DP[mask ^ (1 << to)][from] + c[from][to] + a[to]);
			}
			if (bcount == m)
				ans = max(ans, DP[mask][to]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
