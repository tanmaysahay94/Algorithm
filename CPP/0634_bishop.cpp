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

int n;
const int inf = 2222;
LL v[inf][inf], l[2*inf], r[2*inf], ans[2] = {0}, loc[2][2];

int main()
{
	si(n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sll(v[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			l[i + j] += v[i][j], r[i - j + n] += v[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int bit = (i + j) % 2;
			LL res = l[i + j] + r[i - j + n] - v[i][j];
			if (res >= ans[bit])
			{
				ans[bit] = res;
				loc[bit][0] = i;
				loc[bit][1] = j;
			}
		}
	cout << ans[0] + ans[1] << endl << loc[0][0] << ' ' << loc[0][1] << ' ' << loc[1][0] << ' ' << loc[1][1] << endl;
}
