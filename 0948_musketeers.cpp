#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL maxn = 4e3 + 5;

int deg[maxn], G[maxn][maxn];
vector<pair<LL, LL> > E;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		G[a][b] = G[b][a] = 1;
		deg[a]++;
		deg[b]++;
		E.push_back(make_pair(a, b));
	}
	vector<LL> v(3);
	LL ans = 10 * maxn;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
		{
			int a = E[i].first, b = E[i].second, c = E[j].first, d = E[j].second;
			if (a == c)
				v[0] = a, v[1] = b, v[2] = d;
			else if (a == d)
				v[0] = a, v[1] = b, v[2] = c;
			else if (b == c)
				v[0] = a, v[1] = b, v[2] = d;
			else if (b == d)
				v[0] = a, v[1] = b, v[2] = c;
			else
				continue;
			if (G[v[0]][v[1]] and G[v[1]][v[2]] and G[v[2]][v[0]])
				ans = min((int)ans, (int)(deg[v[0]] + deg[v[1]] + deg[v[2]] - 6));
		}
	if (ans == 10 * maxn)
		ans = -1;
	cout << ans;
	return 0;
}
