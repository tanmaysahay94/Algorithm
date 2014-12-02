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

LL input()
{
	char tmp[20];
	scanf("%s", tmp);
	LL ret = 0;
	bool fl = false;
	for (LL i = 0; tmp[i]; i++)
	{
		if (tmp[i] == '.')
		{
			fl = true;
			continue;
		}
		ret = 10*ret + (tmp[i] - '0');
	}
	if (!fl)
		ret *= 100;
	return ret;
}

int main()
{
	LL t, n, m;
	SLL(t);
	for (LL test = 1; test <= t; test++)
	{
		SLL(n); SLL(m);
		VLL a(n), count(100);
		for (LL i = 0; i < n; i++)
			a[i] = input();
		sortv(a);
		printf("Case %lld:\n", test);
		for (LL scenario = 1; scenario <= m; scenario++)
		{
			printf("Scenario %lld:\n", scenario);
			LL amount = input();
			for (LL i = n - 1; i >= 0; i--)
			{
				count[i] = amount/a[i];
				amount %= a[i];
			}
			for (LL i = n - 1; i >= 0; i--)
			{
				if (not count[i])
					continue;
				if (a[i] < 100)
				{
					double val = a[i]/100.0;
					printf("%.2lf %lld\n", val, count[i]);
				}
				else
					printf("%lld %lld\n", a[i]/100, count[i]);
			}
		}
	}
	return 0;
}
