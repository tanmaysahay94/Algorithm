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
	LL n, r, avg, a, b;
	SLL(n); SLL(r); SLL(avg);
	LL required = n * avg;
	LL cur = 0;
	LL ans = 0;
	vector<pair<LL, LL> > v(n);
	for (LL i = 0; i < n; i++)
	{
		SLL(a); SLL(b);
		cur += a;
		v[i] = mp(b, a);
	}
	sortv(v);
	for (LL i = 0; i < n; i++)
	{
		if (v[i].s < r and cur < required)
		{
			LL gradeToAdd = min(r - v[i].s, required - cur);
			ans += gradeToAdd * v[i].f;
			v[i].s += gradeToAdd;
			cur += gradeToAdd;
		}
	}
	cout << ans << endl;
	return 0;
}
