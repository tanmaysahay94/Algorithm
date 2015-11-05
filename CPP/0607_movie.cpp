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

int main()
{
	LL n, x;
	cin >> n >> x;
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].f >> v[i].s;
	sortv(v);
	LL ans = 0, ptr = 1;
	for (int i = 0; i < n; i++)
	{
		LL diff = v[i].f - ptr;
		ans += diff%x;
		ans += v[i].s - v[i].f + 1;
		ptr = v[i].s + 1;
	}
	cout << ans << endl;
	return 0;
}
