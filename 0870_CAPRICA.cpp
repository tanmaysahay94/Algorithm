#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const LL inf = 1e12;

int dijkstra(vector<vector<PLL> >& G, set<int>& X, set<int>& Y)
{
	int n = G.size();
	vector<bool> visited(n, false);
	priority_queue<PLL> pq;
	for (auto x: X)
		pq.push(make_pair(0, x));
	while (not pq.empty())
	{
		PLL rem = pq.top(); pq.pop();
		LL loc = rem.second;
		LL wt = rem.first;
		if (visited[loc])
			continue;
		visited[loc] = true;
		if (Y.count(loc))
			return -wt;
		for (auto node: G[loc])
			if (not visited[node.first])
				pq.push(make_pair(wt - node.second, node.first));
	}
	return -1;
}

int main()
{
	int n, m, a, b;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	while (n + m + a + b)
	{
		set<int> X, Y;
		for (int i = 0; i < a; i++)
		{
			int city;
			scanf("%d", &city);
			X.insert(city);
		}
		for (int i = 0; i < b; i++)
		{
			int city;
			scanf("%d", &city);
			Y.insert(city);
		}
		vector<vector<PLL> > G(n);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			G[u].push_back(make_pair(v, w));
			G[v].push_back(make_pair(u, w));
		}
		printf("%d\n", dijkstra(G, X, Y));
		scanf("%d%d%d%d", &n, &m, &a, &b);
	}
	return 0;
}
