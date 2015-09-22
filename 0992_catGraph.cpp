#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
int n, m;
vector<int> a, vis;
vector<int> G[maxn];
int ans;

void dfs(int v, int cnt)
{
	if (vis[v])
		return;
	vis[v] = 1;
	if (cnt > m)
		return;
	if ((int) G[v].size() == 1 and v != 1)
		ans++;
	for (auto u: G[v])
	{
		int nxt = cnt;
		if (a[u] == 0)
			nxt = 0;
		else
			nxt += a[u];
		dfs(u, nxt);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	vis = a = vector<int> (n + 1);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	ans = 0;
	dfs(1, a[1]);
	printf("%d\n", ans);
	return 0;
}
