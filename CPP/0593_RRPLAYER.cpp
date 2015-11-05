#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int t;
	si(t);
	while (t--)
	{
/*		double ans = 0;
		double n;
		scanf("%lf", &n);
		for (int i = 1; i <= (int) n; i++)
			ans += n/i;
		printf("%.1lf\n", ans);*/
		int n;
		si(n);
		vector<double> ans(n + 1);
		ans[1] = 1;
		for (int i = 2; i <= n; i++)
			ans[i] = ans[i - 1]/((double) (i-1)) * ((double) i) + 1;
		printf("%.1lf\n", ans[n]);
	}
	return 0;
}
