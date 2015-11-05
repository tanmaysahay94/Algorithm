#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n, m, k, x, y, i ,j, curr, flag;
	SLL(n); SLL(m); SLL(k);
	vector<vector<LL> > grid(n + 1, vector<LL> (m + 1, 1));
	vector<pair<LL, LL> > horAns, verAns, out;
	for (i = 0; i < k; i++)
	{
		SLL(x); SLL(y);
		grid[x][y] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		curr = 0;
		for (j = 1; j <= m; j++)
		{
			if (grid[i][j] and not curr)
				horAns.pb(mp(i, j));
			curr = grid[i][j];
		}
	}
	for (i = 1; i <= m; i++)
	{
		curr = 0;
		for (j = 1; j <= n; j++)
		{
			if (grid[j][i] and not curr)
				verAns.pb(mp(j, i));
			curr = grid[j][i];
		}
	}
	if (horAns.size() < verAns.size())
		flag = 0;
	else
		flag = 1;
	if (flag)
		out = verAns;
	else
		out = horAns;
	printf("%lld\n", (LL)out.size());
	for (i = 0; i < out.size(); i++)
		printf("%lld %lld %lld\n", out[i].f, out[i].s, flag);
	return 0;
}
