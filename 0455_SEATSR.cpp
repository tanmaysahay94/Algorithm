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

const LL inf = 1e12;

int main()
{
	LL t, a, b, k, lens, lenw, now, then, i, j;
	char s[100010], w[100010];
	LL dp[2][100010];
	SLL(t);
	while (t--)
	{
		scanf("%s%s", s, w);
		SLL(a); SLL(b); SLL(k);
		lens = strlen(s); lenw = strlen(w);
		LL ans = abs(lens - lenw) * a;
		if (ans > k)
		{
			printf("-1\n");
			continue;
		}
		if (not a or not b)
		{
			printf("%lld\n", ans);
			continue;
		}
		for (i = 0; i <= lenw; i++)
			dp[0][i] = a * i;
		for (i = 1; i <= lens; i++)
		{
			now = i & 1;
			then = !now;
			dp[now][0] = a * i;
			if (i > k)
				dp[now][i - k - 1] = inf;
			for (j = max(i - k, 1LL); j <= min(lenw, i + k); j++)
				dp[now][j] = min(dp[then][j - 1] + b * (s[i - 1] != w[j - 1]), min(dp[then][j], dp[now][j - 1]) + a);
			if (j <= lenw)
				dp[now][j] = inf;
		}
		if (dp[lens & 1][lenw] <= k)
			printf("%lld\n", dp[lens & 1][lenw]);
		else
			printf("-1\n");
	}
	return 0;
}
