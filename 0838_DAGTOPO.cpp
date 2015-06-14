#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> G[1111];
int vis[1111];
int n;
int color[1111];
vector<int> in;

void init()
{
	for (int i = 0; i < 1111; i++)
	{
		G[i].clear();
		vis[i] = 0;
		color[i] = -1;
	}
}

bool dfs(int node, int hue)
{
	if (vis[node])
	{
		if (hue == color[node])
			return true;
		return false;
	}
	vis[node] = 1;
	color[node] = hue;
	bool ret = false;
	for (int i = 0; i < (int) G[node].size(); i++)
		ret = dfs(G[node][i], hue);
	return ret;
}

bool cyclePresent()
{
	bool present = false;
	for (int i = 0; i < n and not present; i++)
		if (not vis[i])
			present = dfs(i, i);
	return present;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; T++)
	{
		int r;
		scanf("%d%d", &n, &r);
		in = vector<int> (n);
		int u, v;
		init();
		for (int i = 0; i < r; i++)
		{
			scanf("%d%d", &u, &v);
			G[v].push_back(u);
			in[u]++;
		}
		if (cyclePresent())
			printf("Case %d: Never Ends\n", T);
		else
		{
			int ans = 1;
			queue<pair<int, int> > q;
			for (int i = 0; i < n; i++)
				if (in[i] == 0)
					q.push(make_pair(i, 1));
			while (!q.empty())
			{
				pair<int, int> rem = q.front(); q.pop();
				ans = max(ans, rem.second);
				for (int i = 0; i < (int) G[rem.first].size(); i++)
				{
					in[G[rem.first][i]]--;
					if (!in[G[rem.first][i]])
						q.push(make_pair(G[rem.first][i], rem.second + 1));
				}
			}
			printf("Case %d: %d semester(s)\n", T, ans);
		}
	}
	return 0;
}
