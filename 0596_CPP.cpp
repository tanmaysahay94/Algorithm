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
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

double dist(pair<double, double> a, pair<double, double> b)
{
	return sqrt(pow(a.f-b.f, 2) + pow(a.s-b.s, 2));
}

int main()
{
	int n;
	si(n);
	double ans = INT_MAX;
	vector<pair<double, double> > v(n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &v[i].f, &v[i].s);
	sortv(v);
	for (int i = 0; i < n - 1; i++)
		ans = min(ans, dist(v[i], v[i+1]));
	printf("%.6lf\n", ans);
	return 0;
}
