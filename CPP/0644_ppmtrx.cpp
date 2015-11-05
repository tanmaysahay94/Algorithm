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

int main()
{
	int n, m, d;
	si(n); si(m); si(d);
	bool possible = true;
	VI val(n * m);
	int sz = n * m;
	for (int i = 0; i < sz; i++)
		si(val[i]);
	for (int i = 1; i < sz and possible; i++)
		if (val[i] % d != val[i - 1] % d)
			possible = false;
	if (!possible)
		cout << -1 << endl;
	else
	{
		int ans = 0;
		sortv(val);
		int idx = sz/2;
		for (int i = 0; i < sz; i++)
			ans += abs(val[i] - val[idx]) / d;
		cout << ans << endl;
	}
	return 0;
}
