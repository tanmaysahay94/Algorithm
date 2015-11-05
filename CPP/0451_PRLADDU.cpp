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
	LL t, n;
	SLL(t);
	while (t--)
	{
		LL val, ans = 0;
		SLL(n);
		vector<pair<LL, LL> > din, vil;
		for (int i = 0; i < n; i++)
		{
			SLL(val);
			if (val > 0)
				vil.pb(mp(val, i));
			else
				din.pb(mp(-val, i));
		}
		LL dinSize = din.size(), vilSize = vil.size(), i = 0, j = 0;
		while (i < dinSize and j < vilSize)
		{
			ans += abs(vil[j].s - din[i].s) * min(vil[j].f, din[i].f);
			if (din[i].f < vil[j].f)
			{
				vil[j].f -= din[i].f;
				din[i++].f = 0;
			}
			else if (din[i].f > vil[j].f)
			{
				din[i].f -= vil[j].f;
				vil[j++].f = 0;
			}
			else
			{
				din[i].f = vil[j].f = 0;
				i++;
				j++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
