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
	LL h, n;
	cin >> h >> n;
	n--;
	LL expected = 0, ans = 0;
	for (LL i = h - 1; i >= 0; i--)
		if (((n >> i) & 1) == expected)
			ans++, expected = !expected;
		else
			ans += (1LL << (i + 1));
	cout << ans << endl;
	return 0;
}
