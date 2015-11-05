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

inline LL choose(LL val)
{
	return val * (val - 1) / 2;
}

int main()
{
	int n, k, sum = 0;
	si(n); si(k);
	VLL v(n+1, 0), mod(k);
	for (int i = 1; i <= n; i++)
		sll(v[i]);
	mod[0]++;
	for (int i = 1; i <= n; i++)
	{
		sum = (sum + v[i]) % k;
		mod[sum]++;
	}
	LL ans = 0;
	for (int i = 0; i < k; i++)
		ans += choose(mod[i]);
	printf("%lld\n", ans);
	return 0;
}
