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
	double ans = 0.0;
	int m, n;
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		double it = i;
		double a = pow((it/m), n);
		double b = pow((it-1)/m, n);
		ans += it * (a - b);
	}
	printf("%.6lf\n", ans);
	return 0;
}
