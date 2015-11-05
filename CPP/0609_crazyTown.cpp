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

int check(LL sx, LL sy, LL ux, LL uy, LL a, LL b, LL c)
{
	LL v1 = sx*a + sy*b + c;
	LL v2 = ux*a + uy*b + c;
	if ((v1 <= 0 and v2 <= 0) or (v1 >= 0 and v2 >= 0))
		return 0;
	return 1;
}

int main()
{
	LL sx, sy, ux, uy, n, a, b, c;
	cin >> sx >> sy >> ux >> uy >> n;
	LL ans = 0;
	while (n--)
	{
		cin >> a >> b >> c;
		ans += check(sx, sy, ux, uy, a, b, c);
	}
	cout << ans << endl;
	return 0;
}
