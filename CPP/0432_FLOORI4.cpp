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
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL p4(LL v, LL mod)
{
	v %= mod;
	LL ans = v;
	ans *= (2 * v + 1);
	ans %= mod;
	ans *= v + 1;
	ans %= mod;
	ans *= (3 * v * (v + 1) - 1) % mod;
	ans %= mod;
	ans /= 30;
	ans %= (mod / 30);
	return ans;
}

int main()
{
	LL t, n, m;
	SLL(t);
	while (t--)
	{
		LL ans = 0;
		SLL(n); SLL(m);
		LL mt = 30 * m;
		LL cur = 1, next;
		while (cur <= n)
		{
			LL toMult = n/cur;
			next = n/toMult;
			ans += toMult * (p4(next, mt) - p4(cur - 1, mt));
			ans %= m;
			cur = next + 1;
		}
		ans %= m;
		if (ans < 0)
			ans += m;
		printf("%lld\n", ans);
	}
	return 0;
}
