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
	int val, n, mx = INT_MIN;
	cin >> n;
	VLL cnt(111111, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		mx = max(mx, val);
		cnt[val]++;
	}
	VLL dp(111111, 0);
	dp[1] = cnt[1];
	for (int i = 2; i <= mx; i++)
		dp[i] = max(dp[i - 1], cnt[i]*i+dp[i - 2]);
	cout << dp[mx] << endl;
	return 0;
}
