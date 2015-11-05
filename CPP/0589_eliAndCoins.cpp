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

const LL mod = 1e9 + 7;

int main()
{
	int t;
	si(t);
	while (t--)
	{
		LL n;
		sll(n);
		LL sum = 0;
		for (LL i = 1; i < n; i++)
		{
			LL tmp = (i*(i+1))/2;
			tmp %= mod;
			sum = (sum + tmp) % mod;
		}
		sum = (sum * 2) % mod;
		for (LL i = 1; i < n; i++)
			sum = (sum * i) % mod;
		printf("%lld\n", sum);
	}
	return 0;
}
