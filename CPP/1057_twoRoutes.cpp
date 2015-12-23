#include <bits/stdc++.h>

using namespace std;

int f(vector<vector<int> >& G)
{
	int n = G.size();
	vector<int> vis(n);
	queue<pair<int, int> > Q;
	Q.push(make_pair(0, 0));
	vis[0] = 1;
	int ans = -1;
	while (Q.size())
	{
		pair<int, int> rem = Q.front();
		Q.pop();
		int u = rem.first;
		int t = rem.second;
		if (u == n - 1)
		{
			ans = t;
			break;
		}
		for (auto v: G[u])
			if (not vis[v])
			{
				Q.push(make_pair(v, t + 1));
				vis[v] = 1;
			}
	}
	return ans;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (m == 0 or m == (n * (n - 1)) / 2)
	{
		printf("-1");
		return 0;
	}
	vector<vector<int> > mp(n, vector<int> (n));
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		mp[u][v] = mp[v][u] = 1;
	}
	vector<vector<int> > G(n), H(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mp[i][j])
				G[i].push_back(j);
			else
				H[i].push_back(j);
	if (mp[0][n - 1])
		printf("%d\n", f(H));
	else
		printf("%d\n", f(G));
	return 0;
}
