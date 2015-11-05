#include <bits/stdc++.h>

using namespace std;

int dfs(int v, vector<vector<int> >& G, vector<int>& vis)
{
	if (vis[v])
		return 0;
	vis[v] = true;
	int cnt = 1;
	for (auto g: G[v])
		cnt += dfs(g, G, vis);
	return cnt;
}

int main()
{
	int n, d, a, b;
	scanf("%d%d", &n, &d);
	vector<vector<int> > v(n);
	for (int i = 0; i < d; i++)
	{
		scanf("%d%d", &a, &b);
		a--; b--;
		v[a].push_back(b);
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		vector<int> vis(n, false);
		ans = min(ans, dfs(i, v, vis));
	}
	printf("%d\n", ans);
	return 0;
}
