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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n, m, p, row, col;
	SLL(n); SLL(m); SLL(p);
	vector<VLL> v(n);
	VLL count(100100, 0);
	for (int i = 0; i < p; i++)
	{
		SLL(row), SLL(col);
		row--, col--;
		v[row].pb(col);
	}
	for (int i = 0; i < n; i++)
	{
		int s = sz(v[i]);
		for (int j = 0; j < s; j++)
			count[v[i][j]]++;
		LL ans = m - 1 + count[m - 1] - count[0];
		for (int j = 0; j < s; j++)
		{
			LL val = v[i][j];
			if ((val > 0 and count[val - 1] - count[val] > 1) or (val < m - 1 and count[val] - count[val + 1] > 1))
			{
				ans = -1;
				break;
			}
		}
		for (int j = 0; j < s; j++)
			count[v[i][j]] = 0;
		printf("%lld\n", ans);
	}
	return 0;
}
