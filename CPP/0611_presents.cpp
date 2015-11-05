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

LL cnt[2], v[2];

inline bool possible(LL val)
{
	LL a[] = {val/v[0], val/v[1]};
	LL l = v[0] * v[1];
	LL both = val/l;
	LL other = val - a[0] - a[1] + both;
	a[0] -= both;
	a[1] -= both;
	LL tcnt[] = {cnt[0] - a[1], cnt[1] - a[0]};
	for (int i = 0; i < 2; i++)
		if (tcnt[i] < 0)
			tcnt[i] = 0;
	return (tcnt[0] + tcnt[1] <= other);
}

int main()
{
	cin >> cnt[0] >> cnt[1] >> v[0] >> v[1];
	LL l = 0, r = 1e18;
	while (r - l > 1)
	{
		LL mid = (r + l) >> 1;
		if (possible(mid))
			r = mid;
		else
			l = mid;
	}
	cout << r << endl;
	return 0;
}
