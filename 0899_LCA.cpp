#include <bits/stdc++.h>

using namespace std;

const int maxn = 1111;

vector<int> G[maxn];
vector<vector<int> > dad;
vector<int> tin(maxn), tout(maxn), level(maxn);

int timer, logn;

void dfs(int v, int p, int lvl)
{
	tin[v] = ++timer;
	dad[v][0] = p;
	level[v] = lvl;
	for (int i = 1; i < logn; i++)
		dad[v][i] = dad[dad[v][i - 1]][i - 1];
	for (auto kid: G[v])
		if (kid != p)
			dfs(kid, v, lvl + 1);
	tout[v] = ++timer;
}

bool anc(int u, int v)
{
	return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v)
{
	if (level[u] > level[v])
		swap(u, v);
	int d = level[v] - level[u];
	for (int i = 0; (1 << i) <= d; i++)
		if (d & (1 << i))
			v = dad[v][i];
	if (u == v)
		return u;
	for (int i = logn - 1; i >= 0; i--)
		if (dad[u][i] != dad[v][i])
			u = dad[u][i], v = dad[v][i];
	return dad[u][0];
}

void init()
{
	level = tin = tout = vector<int> (maxn, 0);
	dad = vector<vector<int> > (maxn, vector <int> (logn, 0));
	for (int i = 0; i < maxn; i++)
		G[i].clear();
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; T++)
	{
		timer = 0;
		logn = 20;
		init();
		printf("Case %d:\n", T);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int k;
			scanf("%d", &k);
			while (k--)
			{
				int child;
				scanf("%d", &child);
				G[i].push_back(child);
				G[child].push_back(i);
			}
		}
		dfs(1, 0, 0);
		int q;
		scanf("%d", &q);
		while (q--)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", lca(u, v));
		}
	}
	return 0;
}
