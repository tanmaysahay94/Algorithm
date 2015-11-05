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

LL largeModMult(LL a, LL b, LL mod)
{
	if (b == 0)
		return 0;
	LL ret = largeModMult(a, b >> 1, mod);
	ret = (ret << 1) % mod;
	if (b & 1)
		ret = (ret % mod + a % mod) % mod;
	return ret % mod;
}

int main()
{
	LL a, b, c;
	cin >> a >> b >> c;
	cout << largeModMult(a, b, c) << endl;
	return 0;
}
