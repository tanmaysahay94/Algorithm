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

int main()
{
	int t;
	si(t);
	for (int test = 1; test <= t; test++)
	{
		int gp, gc, gf, n;
		si(gp); si(gc); si(gf); si(n);
		int lim = 1 << n;
		VI a(n), b(n), c(n);
		for (int i = 0; i < n; i++)
			si(a[i]), si(b[i]), si(c[i]);
		int pro, car, fat, found = 0;
		for (int i = 0; i < lim and not found; i++)
		{
			int mask = i;
			pro = car = fat = 0;
			for (int j = 0; j < n and not found; j++, mask >>= 1)
			{
				if (mask & 1)
					pro += a[j], car += b[j], fat += c[j];
				if (pro == gp and car == gc and fat == gf)
					found = 1;
			}
		}
		printf("Case #%d: ", test);
		if (found)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
