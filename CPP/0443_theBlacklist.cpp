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

LL n, k;
vector<VLL> arr(15, VLL (25));
vector<VLL> dp(1030, VLL (25, -1));
vector<VLL> prefixSum(15, VLL(25, 0));

LL solve(LL mask, LL toKill)
{
	if (toKill == 0)
		return 0;
	if (mask == 0)
		return INT_MAX;
	if (dp[mask][toKill] != -1)
		return dp[mask][toKill];
	LL ans = INT_MAX;
	for (int i = 0; i < k; i++)
		if (mask & (1 << i))
			for (int j = 1; j <= toKill; j++)
				ans = min(ans, prefixSum[i][toKill] - prefixSum[i][j - 1] + solve(mask - (1 << i), j - 1));
	dp[mask][toKill] = ans;
	return ans;
}

int main()
{
	SLL(n); SLL(k);
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
			SLL(arr[i][j]);
		for (int j = 0; j < n; j++)
			prefixSum[i][j + 1] = prefixSum[i][j] + arr[i][j];		// 1 3 5 2 4 --> 0 1 4 9 11 15 (arr[i] --> prefixSum[i])
	}
	printf("%lld\n", solve((1 << k) - 1, n));
	return 0;
}
