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

const LL inf = 333333;
vector<PII> w[inf];
int dp[inf], tmp[inf];

int main()
{
	int n, m, u, v, len;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> len;
		w[len].pb(mp(u, v));
	}
	for (int i = 0; i < inf; i++)
	{
		for (int j = 0; j < (int) w[i].size(); j++)
		{
			int u = w[i][j].f, v = w[i][j].s;
			tmp[v] = 0;
		}
		for (int j = 0; j < (int) w[i].size(); j++)
		{
			int u = w[i][j].f, v = w[i][j].s;
			tmp[v] = max(tmp[v], dp[u] + 1);
		}
		for (int j = 0; j < (int) w[i].size(); j++)
		{
			int u = w[i][j].f, v = w[i][j].s;
			dp[v] = max(dp[v], tmp[v]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[i]);
	cout << ans << endl;
	return 0;
}
