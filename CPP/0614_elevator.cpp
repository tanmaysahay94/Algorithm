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
	LL n, k;
	cin >> n >> k;
	VI v(n);
	for (LL i = 0; i < n; i++)
		cin >> v[i];
	sortv(v);
	LL ans = 0;
	for (LL i = n-1; i >= 0; i -= k)
		ans += 2*(v[max(0LL, i)] - 1);
	cout << ans << endl;
	return 0;
}
