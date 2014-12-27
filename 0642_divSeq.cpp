#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const LL mod = 1e9 + 7;

int main()
{
	LL n, k;
	sll(n); sll(k);
	vector<VLL> dp(k + 1, VLL (n + 1, 0));
	for (LL i = 1; i <= n; i++)
		dp[1][i] = 1;
	for (LL len = 2; len <= k; len++)
		for (LL num = 1; num <= n; num++)
			for (LL it = num; it <= n; it += num)
				dp[len][it] = (dp[len][it] % mod + dp[len-1][num] % mod) % mod;
	LL ans = 0;
	for (LL i = 1; i <= n; i++)
		ans = (ans + dp[k][i]) % mod;
	cout << ans << endl;
	return 0;
}
