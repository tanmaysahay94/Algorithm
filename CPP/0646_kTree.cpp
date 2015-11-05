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
	LL n, k, d;
	cin >> n >> k >> d;
	LL dp[111][2] = {0};
	dp[0][0] = 1;
	for (LL i = 1; i <= n; i++)
	{
		for (LL j = 1; j <= k; j++)
		{
			if (i < j)
				break;
			if (j < d)
				dp[i][0] = (dp[i][0] % mod + dp[i-j][0] % mod) % mod;
			else
				dp[i][1] = (dp[i][1] % mod + dp[i-j][0] % mod) % mod;
			dp[i][1] = (dp[i][1] % mod + dp[i-j][1] % mod) % mod;
		}
	}
	cout << dp[n][1] << endl;
	return 0;
}
