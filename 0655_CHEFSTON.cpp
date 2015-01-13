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
	LL t;
	sll(t);
	VLL a;
	while (t--)
	{
		LL n, k, prof, ans = 0;
		sll(n); sll(k);
		a = VLL (n);
		for (int i = 0; i < n; i++)
			sll(a[i]);
		for (int i = 0; i < n; i++)
		{
			sll(prof);
			ans = max(ans, (k/a[i]) * prof);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
