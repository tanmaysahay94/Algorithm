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
	int ans = 0, n, a, b, c;
	si(n); si(a); si(b); si(c);
	int v[] = {a, b, c};
	sort(v, v+3);
	int lim[] = {n/v[0], n/v[1], n/v[2]};
	for (int i = 0; i <= lim[2]; i++)
		for (int j = 0; j <= lim[1]; j++)
		{
			int curr = i * v[2] + j * v[1];
			if (n-curr >= 0 and (n-curr) % v[0] == 0)
				ans = max(ans, i + j + (n-curr)/v[0]);
		}
	cout << ans << endl;
	return 0;
}
