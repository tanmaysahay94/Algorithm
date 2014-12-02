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

int main()
{
	LL n;
	double l;
	cin >> n >> l;
	vector<double> v(n);
	for (LL i = 0; i < n; i++)
		scanf("%lf", &v[i]);
	sortv(v);
	double ans = 0;
	ans = max(ans, v[0]);
	ans = max(ans, l-v[n-1]);
	for (LL i = 0; i < n - 1; i++)
		ans = max(ans, (v[i+1]-v[i])/2);
	printf("%.9lf\n", ans);
	return 0;
}
