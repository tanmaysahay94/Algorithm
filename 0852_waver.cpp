#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;
typedef pair<LL, LL> pll;

const LL inf = 1e11;
const LL maxn = 1e4 + 3;
const LL maxk = 1e3 + 3;

vector<vector<LL> > ans(maxn, vector<LL> (maxk));
vector<pll> G[maxn], S[maxn];

LL n, e, k;

void dfs(LL curr, LL par, LL sh, LL dir)
{
	for (auto node: G[curr])
	{
		LL next = node.first;
		LL wt = node.second;
		if (next == par)
			continue;
		if (dir == 0)
		{
			dfs(next, curr, sh, dir);									
			ans[curr][sh] = min(ans[curr][sh], ans[next][sh] + wt);		// set this value once next has been set, i.e., when recursing back
		}
		else
		{
			ans[next][sh] = min(ans[next][sh], ans[curr][sh] + wt);		// set next value before recursing forward. this way both directions are taken care of
			dfs(next, curr, sh, dir);
		}
	}
}

int main()
{
	optimizeIO();
	cin >> n >> e >> k;
	for (int i = 0; i + 1 < n; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		G[a].push_back(make_pair(b, w));
		G[b].push_back(make_pair(a, w));
	}
	for (int i = 0; i < e; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		S[a].push_back(make_pair(b, w));
		S[b].push_back(make_pair(a, w));
	}
	for (int u = 1; u <= n; u++)
		if (G[u].size() < 2)
			ans[u][0] = 0;
		else
			ans[u][0] = inf;
	dfs(1, 0, 0, 0);
	dfs(1, 0, 0, 1);
	for (int sh = 1; sh <= k; sh++)
	{
		for (int u = 1; u <= n; u++)
		{
			ans[u][sh] = ans[u][sh - 1];
			for (auto node: S[u])
			{
				LL v = node.first;
				LL wt = node.second;
				ans[u][sh] = min(ans[u][sh], ans[v][sh - 1] + wt);
			}
		}
		dfs(1, 0, sh, 0);
		dfs(1, 0, sh, 1);
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i][k] << '\n';
	return 0;
}
