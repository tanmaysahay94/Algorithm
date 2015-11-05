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

int main()
{
	LL n, k;
	cin >> n >> k;
	vector<VLL> v, dp;
	v = dp = vector<VLL> (n, VLL (k));
	for (LL i = 0; i < n; i++)
		for (LL j = 0; j < k; j++)
			cin >> v[i][j];
	dp[0][0] = v[0][0];
	for (LL i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + v[i][0];
	for (LL i = 1; i < k; i++)
		dp[0][i] = dp[0][i - 1] + v[0][i];
	for (LL i = 1; i < n; i++)
		for (LL j = 1; j < k; j++)
			dp[i][j] = v[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
	for (LL i = 0; i < n; i++)
		cout << dp[i][k - 1] << ' ';
	cout << endl;
	return 0;
}
