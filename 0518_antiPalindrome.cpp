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

const LL mod = 1e9 + 7;

LL powMod(LL a, LL b)
{
	LL ans = 1;
	a %= mod;
	while (b)
	{
		if (b & 1)
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int main()
{
	LL t, n, m;
	SLL(t);
	while (t--)
	{
		SLL(n); SLL(m);
		m %= mod;
		LL ans;
		if (n == 1) ans = powMod(m, n);
		else if (n == 2) ans = (m * (m - 1)) % mod;
		else ans = (((m * (m - 1)) % mod) * powMod(m - 2, n - 2)) % mod;
		printf("%lld\n", ans);
	}
	return 0;
}
