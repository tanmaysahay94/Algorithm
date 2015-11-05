#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n, m;
vector<int> G[111];
vector<int> C(111);
vector<int> V(111);

int dfs(int v)
{
	if (V[v])
		return 0;
	V[v] = 1;
	int c = 1;
	if (not G[v].size())
		return C[v] = c;
	for (int i = 0; i < (int) G[v].size(); i++)
		c += dfs(G[v][i]);
	return C[v] = c;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	C[1] = dfs(1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (C[i] % 2 == 0)
			ans++;
	printf("%d\n", ans - 1);
	return 0;
}
