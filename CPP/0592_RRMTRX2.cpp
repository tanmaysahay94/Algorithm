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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const LL mod = 1e7 + 7;

int main()
{
	LL n, m;
	sll(n); sll(m);
	vector<VLL> v(n, VLL(m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			sll(v[i][j]);
	LL ans = 1;
	for (int i = 0; i < m; i++)
	{
		LL sum = 0;
		for (int j = 0; j < n; j++)
			sum += v[j][i];
		sum %= mod;
		if (sum < 0) sum += mod;
		ans = ((ans%mod) * (sum%mod)) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
