#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL n, m, k;
LL sum[5050];

LL ans(vector<vector<LL> >& dp, int sets, int idx)
{
	if(sets <= 0)
		return 0;
	if(idx < m - 1)
		return 0;
	if(dp[sets][idx] == -1)
		dp[sets][idx] = max(ans(dp, sets, idx - 1), ans(dp, sets - 1, idx - m) + sum[idx + 1] - sum[idx + 1 - m]);
	return dp[sets][idx];
}

int main()
{
	LL i;
	LL a[5050];
	SLL(n); SLL(m); SLL(k);
	sum[0] = 0;
	for (i = 0; i < n; i++)
	{
		SLL(a[i]);
		sum[i + 1] = sum[i] + a[i];
	}
	vector<vector<LL> > dp(k + 1, vector<LL>(n, -1));
	cout << ans(dp, k, n-1) << endl;
	return 0;
}
