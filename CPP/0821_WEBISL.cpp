#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL n, m;

vector<vector<LL> > G, GR;
vector<LL> vis, ans, comp;
stack<LL> S;

void dfs1(LL v)
{
	if (vis[v]) return;
	vis[v] = 1;
	for (int i = 0; i < (int) G[v].size(); i++)
		dfs1(G[v][i]);
	S.push(v);
}

void dfs2(LL v, LL& mn)
{
	if (vis[v]) return;
	vis[v] = 1;
	comp.push_back(v);
	mn = min(mn, v);
	for (int i = 0; i < (int) GR[v].size(); i++)
		dfs2(GR[v][i], mn);
}

int main()
{
	LL x, y;
	scanf("%lld%lld", &n, &m);
	G.resize(n), GR.resize(n), vis.resize(n), ans.resize(n);
	for (LL i = 0; i < m; i++)
	{
		scanf("%lld%lld", &x, &y);
		G[x].push_back(y);
		GR[y].push_back(x);
	}
	for (LL i = 0; i < n; i++) if (not vis[i]) dfs1(i);
	for (LL i = 0; i < n; i++) vis[i] = 0;
	while (!S.empty())
	{
		LL v = S.top(); S.pop();
		if (vis[v]) continue;
		comp.clear();
		LL mn = v;
		dfs2(v, mn);
		for (int i = 0; i < (int) comp.size(); i++)
			ans[comp[i]] = mn;
	}
	for (int i = 0; i < n; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
