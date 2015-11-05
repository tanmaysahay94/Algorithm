#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n;
vector<pair<int, int> > G[111111];
vector<int> vis, ans;

bool dfs(int node, int problem = 1)
{
	vis[node] = 1;
	bool tmp = false;
	for (int i = 0; i < (int) G[node].size(); i++)
		if (!vis[G[node][i].first])
			tmp |= dfs(G[node][i].first, G[node][i].second);
	if (tmp) return true;
	if (problem == 2)
	{
		ans.push_back(node + 1);
		return true;
	}
	return false;
}

int main()
{
	optimizeIO();
	cin >> n;
	vis = vector<int> (n);
	for (int i = 1; i < n; i++)
	{
		int x, y, t;
		cin >> x >> y >> t;
		x--; y--;
		G[x].push_back(make_pair(y, t));
		G[y].push_back(make_pair(x, t));
	}
	dfs(0);
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << ' ';
	return 0;
}
