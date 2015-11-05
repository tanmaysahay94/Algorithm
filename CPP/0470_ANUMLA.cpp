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
	LL t, n, i, j;
	SLL(t);
	while (t--)
	{
		SLL(n);
		VLL ans, sums;
		LL size = 1 << n;
		vector<pair<LL, LL> > v(size);
		vector<pair<LL, LL> >::iterator it;
		for (i = 0; i < size; i++)
		{
			SLL(v[i].f);
			v[i].s = 1;
		}
		sortv(v);
		v[0].s = 0;
		for (i = 1; i < size; i++)
		{
			if (v[i].s)
			{
				v[i].s = 0;
				printf("%lld ", v[i].f);
				LL sz = sums.size();
				for (j = 0; j < sz; j++)
				{
					LL sum = sums[j] + v[i].f;
					sums.pb(sum);
					it = lower_bound(v.begin(), v.end(), mp(sum, 1LL));
					it->s = 0;
				}
				sums.pb(v[i].f);
			}
		}
		printf("\n");
	}
	return 0;
}
