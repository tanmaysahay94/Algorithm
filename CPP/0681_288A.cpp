#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

set<PLL> pt;

bool lookfor(pair<LL, LL> p)
{
	return pt.find(p) != pt.end();
}

int main()
{
	LL i, j, k, ans = 0;
	sll(i), sll(j), sll(k);
	for (LL t = 1; t <= k; t++)
	{
		sll(i), sll(j);
		pt.insert(mp(i, j));
		bool sq1 = lookfor(mp(i-1, j-1)) and lookfor(mp(i-1, j)) and lookfor(mp(i, j-1));
		bool sq2 = lookfor(mp(i-1, j)) and lookfor(mp(i-1, j+1)) and lookfor(mp(i, j+1));
		bool sq3 = lookfor(mp(i, j+1)) and lookfor(mp(i+1, j+1)) and lookfor(mp(i+1, j));
		bool sq4 = lookfor(mp(i, j-1)) and lookfor(mp(i+1, j-1)) and lookfor(mp(i+1, j));
		if (sq1 or sq2 or sq3 or sq4)
		{
			ans = t;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
