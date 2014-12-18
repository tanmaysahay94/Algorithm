#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const LL mod = 1e9 + 7;

int n;
vector<VLL> dp(111, VLL(111, 0LL));
VLL v;

LL calculate(int start, int end)
{
	if (start < n and end < n and start >= 0 and end >= 0)
	{
		if (dp[start][end])
			return dp[start][end];
		if (start >= end)
			return dp[start][end] = 1;
		if (v[start] < 0 and v[start] == -v[end])
			return dp[start][end] = (2 * calculate(start + 1, end - 1)) % mod;
		LL ans = calculate(start + 1, end) % mod;
		if (v[start] < 0)
			for (int i = end; i > start; i--)
				if (v[start] == -v[i])
					ans = (ans + (calculate(start + 1, i - 1)%mod * calculate(i + 1, end)%mod) % mod) % mod;
		return dp[start][end] = ans;
	}
}

int main()
{
	si(n);
	v.resize(n);
	for (int i = 0; i < n; i++)
		sll(v[i]);
	for (int i = 0; i < n; i++)
		for (int j = i; j >= 0; j--)
			dp[i][j] = 1;
	printf("%lld\n", calculate(0, n - 1));
	return 0;
}
