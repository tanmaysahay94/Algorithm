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

LL pow(LL a, LL b)
{
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret *= a;
		a *= a;
		b >>= 1;
	}
	return ret;
}

LL digsum(LL val)
{
	LL ret = 0;
	while (val)
	{
		ret += val%10;
		val /= 10;
	}
	return ret;
}

int main()
{
	VLL ans;
	LL a, b, c;
	cin >> a >> b >> c;
	for (LL i = 1; i <= 81; i++)
	{
		LL val = b * pow(i, a) + c;
		LL chk = digsum(val);
		if (chk == i and val < (LL) 1e9)
			ans.pb(val);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
