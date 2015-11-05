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
	LL t, r, g, b, m;
	SLL(t);
	while (t--)
	{
		LL val, rmax = INT_MIN, gmax = INT_MIN, bmax = INT_MIN;
		SLL(r); SLL(g); SLL(b); SLL(m);
		for (int i = 0; i < r; i++)
		{
			SLL(val);
			rmax = max(rmax, val);
		}
		for (int i = 0; i < g; i++)
		{
			SLL(val);
			gmax = max(gmax, val);
		}
		for (int i = 0; i < b; i++)
		{
			SLL(val);
			bmax = max(bmax, val);
		}
		VLL v(3), ans;
		v[0] = rmax; v[1] = gmax; v[2] = bmax;
		sortv(v);
		ans.pb(v[2]);
		for (int i = 0; i < m; i++)
		{
			v[2] >>= 1;
			sortv(v);
			ans.pb(v[2]);
		}
		val = INT_MAX;
		for (int i = 0; i < ans.size(); i++)
			val = min(val, ans[i]);
		printf("%lld\n", val);
	}
	return 0;
}
