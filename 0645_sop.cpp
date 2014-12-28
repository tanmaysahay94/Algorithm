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

const LL mod = 1e9 + 7;

__int128_t sum(LL val)
{
	return (val * (val + 1)) >> 1;
}

__int128_t calc(LL val)
{
	__int128_t ret = 0, i = 1;
	while (i <= val)
	{
		__int128_t quo = val/i;
		__int128_t start = i;
		__int128_t end = val/quo;
		i = end + 1;
		ret += quo * (sum(end) - sum(start - 1));
	}
	return ret % mod;
}

int main()
{
	int t;
	si(t);
	while (t--)
	{
		LL n;
		sll(n);
		LL out = calc(n);
		cout << out << endl;
	}
	return 0;
}
