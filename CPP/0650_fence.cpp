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

LL choose(VLL& v, int len, LL lit)
{
	LL ans;
	for (LL i = 0; i < (LL) len; i++)
		if (v[i] <= lit)
			ans = i;
	return ans + 1;
}

int main()
{
	LL lit, mn = INT_MAX;
	cin >> lit;
	VLL v(9);
	for (LL i = 0; i < 9; i++)
	{
		cin >> v[i];
		mn = min(mn, v[i]);
	}
	LL dig = lit/mn;
	if (!dig)
	{
		cout << -1 << endl;
		return 0;
	}
	LL used;
	used = mn * (dig - 1);
	for (LL i = 0; i < dig; i++)
	{
		LL idx = choose(v, 9, lit - used);
		lit -= v[idx - 1];
		printf("%lld", idx);
		used -= mn;
	}
	cout << endl;
	return 0;
}
