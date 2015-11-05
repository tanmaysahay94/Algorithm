#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n, m;
vector<int> G[111];
vector<int> vis;
vector<int> D;
int cycle;

void dfs(int node, int depth)
{
	if (vis[node])
	{
		if (D[node] != -1 and depth - D[node] > 2)
			cycle++;
		return;
	}
	vis[node] = 1;
	D[node] = depth;
	for (int i = 0; i < (int) G[node].size(); i++)
		dfs(G[node][i], depth + 1);
}

int main()
{
	optimizeIO();
	cin >> n >> m;
	vis = vector<int> (n, 0);
	D = vector<int> (n, -1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cycle = 0;
	int t = 0;
	for (int i = 0; i < n; i++)
		if (not vis[i])
			dfs(i, 0), t++;
	if (cycle == 1 and t == 1) cout << "FHTAGN!\n";
	else cout << "NO\n";
	return 0;
}
