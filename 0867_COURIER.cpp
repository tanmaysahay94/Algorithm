#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const LL inf = 1e12;
const LL maxn = 101;

LL dist[maxn][maxn];

void floydWarshall()
{
	for (int k = 0; k < maxn; k++)
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

LL bitcount(LL n)
{
	LL ret = 0;
	while (n)
	{
		ret += n & 1;
		n >>= 1;
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		for (int i = 0; i < maxn; i++)
			for (int j = 0; j < maxn; j++)
				dist[i][j] = inf;
		for (int i = 0; i < maxn; i++)
			dist[i][i] = 0;
		int n, m, b;
		scanf("%d%d%d", &n, &m, &b);
		for (int i = 0; i < m; i++)
		{
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			dist[u][v] = dist[v][u] = min(dist[v][u], (LL) w);
		}
		floydWarshall();
		int z;
		scanf("%d", &z);
		vector<PLL> orders;
		set<LL> locations;
		locations.insert(b);
		for (int i = 0; i < z; i++)
		{
			int u, v, parcel;
			scanf("%d%d%d", &u, &v, &parcel);
			locations.insert(u);
			locations.insert(v);
			PLL foo = make_pair(u, v);
			for (int j = 0; j < parcel; j++)
				orders.push_back(foo);
		}
		vector<int> loc;
		for (auto l: locations)
			loc.push_back(l);
		LL rmax = 1 << orders.size();
		LL cmax = loc.size();
		vector<vector<LL> > DP(rmax, vector<LL> (cmax, inf));
		for (int i = 0; i < (int) orders.size(); i++)
		{
			int orderStart = orders[i].first;
			int orderEnd = orders[i].second;
			LL tmpDist = dist[orderStart][orderEnd];
			for (int j = 0; j < (int) loc.size(); j++)
				DP[1 << i][j] = dist[b][orderStart] + tmpDist + dist[orderEnd][loc[j]];
		}
		for (LL mask = 1; mask < rmax; mask++)
		{
			if (bitcount(mask) == 1)
				continue;
			for (int bit = 0; (1 << bit) < mask; bit++)
			{
				if (not (mask & (1 << bit)))
					continue;
				LL otherMask = mask ^ (1 << bit);
				int orderStart = orders[bit].first;
				int orderEnd = orders[bit].second;
				LL tmpDist = dist[orderStart][orderEnd];
				for (int i = 0; i < (int) loc.size(); i++)
					for (int j = 0; j < (int) loc.size(); j++)
						DP[mask][i] = min(DP[mask][i], DP[otherMask][j] + dist[loc[j]][orderStart] + tmpDist + dist[orderEnd][loc[i]]);
			}
		}
		printf("%lld\n", DP[rmax - 1][lower_bound(loc.begin(), loc.end(), b) - loc.begin()]);
	}
	return 0;
}
