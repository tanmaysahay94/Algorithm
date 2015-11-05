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
	LL n, val;
	SLL(n);
	VLL a, b, c;
	for (LL i = 1; i <= n; i++)
	{
		SLL(val);
		if (val == 1)
			a.pb(i);
		else if (val == 2)
			b.pb(i);
		else
			c.pb(i);
	}
	LL p = sz(a);
	LL q = sz(b);
	LL r = sz(c);
	LL ans = min(p, min(q, r));
	cout << ans << endl;
	for (LL i = 0; i < ans; i++)
		cout << a[i] << " "<< b[i] << " " << c[i] << endl;
	return 0;
}
