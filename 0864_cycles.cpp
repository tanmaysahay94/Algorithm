#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

LL ctz(LL v)
{
	LL cnt = 0;
	while (v % 2 == 0)
	{
		cnt++;
		v >>= 1;
	}
	return cnt;
}

LL ppcnt(LL v)
{
	LL cnt = 0;
	while (v)
	{
		cnt += v & 1;
		v >>= 1;
	}
	return cnt;
}

int main()
{
	optimizeIO();
	LL n, m;
	cin >> n >> m;
	LL rmax = (1 << n);
	LL cmax = n;
	vector<vector<LL> > G(n, vector<LL> (n)), DP(rmax, vector<LL> (cmax));
	for (int i = 0; i < m; i++)
	{
		LL x, y;
		cin >> x >> y;
		x--;
		y--;
		G[x][y] = G[y][x] = 1;
	}
	LL lim = (1 << n);
	for (LL mask = 1; mask < lim; mask++)
	{
		LL start = ctz(mask);
		LL cnt = ppcnt(mask);
		for (LL end = 0; end < n; end++)
		{
			if (!(mask & (1 << end)))		// check if end is in subset
				continue;					// end not in subset
			if (cnt == 1)
			{
				DP[mask][end] = 1;
				continue;					// bitcount = 1
			}
			if (start == end)				// bitcount > 1
				continue;					// start == end
			for (LL v = 0; v < n; v++)		// start != end, bitcount > 1, end in subset
				if (G[v][end])
					DP[mask][end] += DP[mask ^ (1 << end)][v];
		}
	}
	LL ans = 0;
	for (LL mask = 1; mask < lim; mask++)
	{
		LL start = ctz(mask);
		LL cnt = ppcnt(mask);
		if (cnt < 3)
			continue;
		for (LL end = 0; end < n; end++)
			if (G[end][start])
				ans += DP[mask][end];
	}
	cout << ans / 2;
	return 0;
}
