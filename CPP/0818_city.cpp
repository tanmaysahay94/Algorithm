#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;
const LL inf = 1LL << 61;

vector<vector<pair<LL, LL> > > G;
bool train[200002] = {false};
LL dist[200002];
LL n, m, t;

void dijk(int s)
{
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, greater<pair<LL, LL> > > pq;
	dist[s] = 0;
	for (int i = 1; i <= n; i++)
		if (dist[i] != inf)
			pq.push(make_pair(dist[i], i));
	while (!pq.empty())
	{
		pair<LL, LL> p = pq.top(); pq.pop();
		LL d = p.first;
		LL u = p.second;
		if (dist[u] < d)
			continue;
		for (int i = 0; i < (int)G[u].size(); i++)
		{
			LL v = G[u][i].second;
			LL dv = G[u][i].first;
			if (dist[v] >= dist[u] + dv)
				if (train[v])
					train[v] = false;
			if (dist[v] > dist[u] + dv)
			{
				dist[v] = dist[u] + dv;
				pq.push(make_pair(dist[v], v));
			}
		}
	}
}

int main()
{
	optimizeIO();
	cin >> n >> m >> t;
	G.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		dist[i] = inf;
		train[i] = false;
	}
	for (LL i = 0; i < m; i++)
	{
		int x, y; LL w;
		cin >> x >> y >> w;
		G[x].push_back(make_pair(w, y));
		G[y].push_back(make_pair(w, x));
	}
	for (LL i = 0; i < t; i++)
	{
		LL x, y;
		cin >> x >> y;
		train[x] = true;
		dist[x] = min(dist[x], y);
	}
	dijk(1);
	LL ans = t;
	for (LL i = 1; i <= n; i++)
		if (train[i])
			ans--;
	cout << ans << endl;
	return 0;
}
