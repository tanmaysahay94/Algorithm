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
	LL n, k, d;
	cin >> n >> k >> d;
	LL tmp = 1;
	bool check = false;
	for (int i = 0; i < d and not check; i++)
	{
		tmp *= k;
		if (tmp >= n)
			check = true;
	}
	if (!check)
	{
		cout << -1 << endl;
		return 0;
	}
	vector<VLL> ans(n, VLL (d));
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < d; j++)
			ans[i][j] = ans[i - 1][j];
		for (int j = d - 1; j >= 0; j--)
		{
			ans[i][j] = (ans[i][j] + 1) % k;
			if (ans[i][j])
				break;
		}
	}
	for (int i = 0; i < d; i++, cout << endl)
		for (int j = 0; j < n; j++)
			cout << ans[j][i] + 1 << " ";
	return 0;
}
