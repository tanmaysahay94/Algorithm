#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

vector<vector<int> > DP, dist;

bool invalid(int mask, int n)
{
	int diff = 0;
	for (int i = 1; i < n; i += 2)
	{
		bool tool = mask & (1 << i);
		bool chef = mask & (1 << (i - 1));
		if (chef and not tool)
			return true;
		if (not chef and tool)
			diff++;
	}
	return (diff > 2);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<pair<int, int> > location;
		for (int i = 0; i < n; i++)
		{
			int cx, cy, tx, ty;
			scanf("%d%d%d%d", &cx, &cy, &tx, &ty);
			location.push_back(make_pair(cx, cy));
			location.push_back(make_pair(tx, ty));
		}
		n = location.size();
		dist = vector<vector<int> > (n, vector<int> (n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dist[i][j] = abs(location[i].first - location[j].first) + abs(location[i].second - location[j].second);
		int lim = 1 << n;
		DP = vector<vector<int> > (lim, vector<int> (n, inf));
		for (int i = 1; i < n; i += 2)
			DP[1 << i][i] = abs(location[i].first) + abs(location[i].second);
		for (int mask = 1; mask < lim; mask++)
		{
			if ((mask & (mask - 1)) == 0)
				continue;
			if (invalid(mask, n))
				continue;
			for (int end = 0; end < n; end++)
			{
				if ((mask & (1 << end)) == 0)
					continue;
				for (int prev = 0; prev < n; prev++)
				{
					if ((mask & (1 << prev)) == 0)
						continue;
					if (prev == end)
						continue;
					int otherMask = mask ^ (1 << end);
					DP[mask][end] = min(DP[mask][end], DP[otherMask][prev] + dist[prev][end]);
				}
			}
		}
		int ans = inf;
		for (int i = 0; i < n; i += 2)
			ans = min(ans, DP[lim - 1][i] + abs(location[i].first) + abs(location[i].second));
		printf("%d\n", ans);
	}
	return 0;
}
