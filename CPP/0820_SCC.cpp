#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

vector<vector<int> > G, GR;
stack<int> S;
vector<bool> vis;
int n;
vector<LL> cost;
vector<LL> foo;

const LL mod = 1e9 + 7;

void dfs1(int i)
{
	if (vis[i]) return;
	vis[i] = 1;
	for (int j = 0; j < (int) G[i].size(); j++)
		dfs1(G[i][j]);
	S.push(i);
}

void dfs2(int i)
{
	if (vis[i]) return;
	vis[i] = 1;
	foo.push_back(cost[i]);
	for (int j = 0; j < (int) GR[i].size(); j++)
		dfs2(GR[i][j]);
}

int main()
{
	optimizeIO();
	cin >> n;
	G.resize(n+1), GR.resize(n+1), vis.resize(n+1), cost.resize(n+1);
	for (int i = 1; i <= n; i++)
		cin >> cost[i];
	int m, x, y; cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		G[x].push_back(y);
		GR[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		if (not vis[i])
			dfs1(i);
	vis.clear(); vis.resize(n+1);
	LL val = 0, ways = 1;
	while (!S.empty())
	{
		int i = S.top(); S.pop();
		if (vis[i]) continue;
		foo.clear();
		dfs2(i);
		sort(foo.begin(), foo.end());
		LL bar = foo[0];
		LL idx = 0;
		while (idx + 1 < (int) foo.size() and foo[idx] == foo[idx + 1]) idx++;
		val += bar;
		ways = (ways * (idx+1)) % mod;
	}
	cout << val << " " << ways << endl;
	return 0;
}
