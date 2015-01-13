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

struct cmp
{
	bool operator() (PLL a, PLL b) 
	{
		return a.s < b.s;
	}
};

int main()
{
	LL t;
	sll(t);
	while (t--)
	{
		LL n;
		sll(n);
		vector<PLL> v(n);
		for (int i = 0; i < n; i++)
			sll(v[i].f), sll(v[i].s);
		sort(v.begin(), v.end(), cmp());
		LL ans = 1, last = v[0].s;
		for (int i = 1; i < n; i++)
		{
			if (v[i].f > last)
			{
				last = v[i].s;
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
