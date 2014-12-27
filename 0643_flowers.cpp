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
	VLL dp((int) 100100);
	LL n, k;
	cin >> n >> k;
	for (int i = 1; i < k; i++)
		dp[i] = 1;
	dp[k] = 2;
	for (int i = k + 1; i < 100100; i++)
	{
		dp[i] = dp[i - 1] + dp[i - k];
		dp[i] %= mod;
	}
	for (int i = 1; i < 100100; i++)
		dp[i] += dp[i - 1];
	for (int i = 0; i < n; i++)
	{
		int p, q;
		cin >> p >> q;
		cout << (dp[q] - dp[p - 1] + mod) % mod << endl;
	}
	return 0;
}
