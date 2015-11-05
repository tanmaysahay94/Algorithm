#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int maxn = 1e4 + 5;
const int logn = 15;

int n, timer;
vector<pair<int, int> > G[maxn];
vector<int> tin(maxn), tout(maxn), L(maxn), dist(maxn);
vector<vector<int> > dad(maxn, vector<int> (logn));

void init()
{
	timer = 0;
	for (int i = 0; i <= n; i++)
		G[i].clear(), dist[i] = tin[i] = tout[i] = L[i] = 0;
	for (int i = 0; i < maxn; i++)
		for (int j = 0; j < logn; j++)
			dad[i][j] = 0;
}

void dfs(int v = 1, int d = 0, int p = 0, int l = 0)
{
	tin[v] = ++timer;
	L[v] = l;
	dad[v][0] = p;
	dist[v] = dist[p] + d;
	for (int i = 1; i < logn; i++)
		dad[v][i] = dad[dad[v][i - 1]][i - 1];
	for (auto kid: G[v])
		if (kid.first != p)
			dfs(kid.first, kid.second, v, l + 1);
	tout[v] = ++timer;
}

int lca(int u, int v)
{
	if (L[u] > L[v])
		swap(u, v);
	int d = L[v] - L[u];
	for (int i = 0; (1 << i) <= d; i++)
		if (d & (1 << i))
			v = dad[v][i];
	if (u == v)
		return u;
	for (int i = logn - 1; i >= 0; i--)
		if (dad[v][i] != dad[u][i])
			v = dad[v][i], u = dad[u][i];
	return dad[u][0];
}

int kth(int u, int v, int k)
{
	int w = lca(u, v);
	int d1 = L[u] - L[w] + 1;
	int d2 = L[v] - L[w] + 1;
	int from;
	if (d1 == k)
		return w;
	else if (d1 < k)
	{
		from = v;
		k = d1 + d2 - k - 1;
	}
	else
	{
		from = u;
		k--;
	}
	int l = logn;
	while (k)
	{
		if (1 << l <= k)
		{
			from = dad[from][l];
			k -= 1 << l;
		}
		l--;
		if (l < 0)
			l = 0;
	}
	return from;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		init();
		for (int i = 1; i < n; i++)
		{
			int a, b, w;
			cin >> a >> b >> w;
			G[a].push_back(make_pair(b, w));
			G[b].push_back(make_pair(a, w));
		}
		dfs();
		string s;
		cin >> s;
		while (s[1] != 'O')
		{
			if (s[1] == 'I')
			{
				int a, b;
				cin >> a >> b;
				int L = lca(a, b);
				cout << dist[a] + dist[b] - (2LL * dist[L]) << '\n';
			}
			else
			{
				int a, b, k;
				cin >> a >> b >> k;
				cout << kth(a, b, k) << '\n';
			}
			cin >> s;
		}
	}
	return 0;
}
