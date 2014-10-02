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
#define ps printf(" ")
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

void p(LL val, LL lim)
{
	if (val == 0)
	{
		while (lim--)
			printf("0");
		return;
	}
	LL dig = ceil(log10(val + 1));
	LL diff = lim - dig;
	while (diff--)
		printf("0");
	printf("%lld", val);
}

int main()
{
	LL t, n;
	SLL(t);
	while (t--)
	{
		SLL(n);
		LL count = 1;
		vector<pair<LL, pair<LL, pair<LL, pair<LL, pair<LL, LL> > > > > > v(n + 1);
		pair<LL, pair<LL, pair<LL, pair<LL, pair<LL, LL> > > > > curr;
		LL a, b, c, d, e, f;
		for (int i = 0; i <= n; i++)
		{
			cin >> a >> b >> c >> d >> e >> f;
			v[i] = mp(a, mp(b, mp(c, mp(d, mp(e, f)))));
		}
		v[n] = mp(999, mp(9999999, mp(9999, mp(9999, mp(9999, 9999)))));
		sortv(v);
		for (int i = 0; i < n; i++)
		{
			if (v[i] == v[i + 1])
			{
				count++;
				curr = v[i];
			}
			else
			{
				p(curr.f, 3); ps; p(curr.s.f, 7); ps; p(curr.s.s.f, 4); ps; p(curr.s.s.s.f, 4); ps; p(curr.s.s.s.s.f, 4); ps; p(curr.s.s.s.s.s, 4); ps; printf("%lld\n", count);
				count = 1;
				curr = v[i + 1];
			}
		}
	}
	return 0;
}
