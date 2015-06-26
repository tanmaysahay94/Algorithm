#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;

const LL inf = 1e12;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<PLL> loc;
		loc.push_back(make_pair(0, 0));
		for (int i = 0; i < n; i++)
		{
			LL cx, cy, tx, ty;
			scanf("%lld%lld%lld%lld", &cx, &cy, &tx, &ty);
			loc.push_back(make_pair(cx, cy));
			loc.push_back(make_pair(tx, ty));
		}
		LL lcount = loc.size();
		vector<vector<LL> > dist(lcount, vector<LL> (lcount, inf));
		for (int i = 0; i < lcount; i++)
			for (int j = 0; j < lcount; j++)
				dist[i][j] = abs(loc[i].first - loc[j].first) + abs(loc[i].second - loc[j].second);
	}
	return 0;
}
