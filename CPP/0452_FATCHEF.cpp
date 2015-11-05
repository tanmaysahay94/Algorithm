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

const LL mod = 1e9 + 9;

int main()
{
	LL t, n, m;
	SLL(t);
	while (t--)
	{
		vector<pair<LL, char> > v;
		char paint;
		LL idx, ans = 1;
		SLL(n); SLL(m);
		getchar();
		for (int i = 0; i < m; i++)
		{
			scanf("%c", &paint);
			SLL(idx);
			v.pb(mp(idx, paint));
			getchar();
		}
		sortv(v);
		for (int i = 0; i < v.size() - 1; i++)
			if (v[i].s != v[i + 1].s)
				ans = (ans * (v[i + 1].f - v[i].f)) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
