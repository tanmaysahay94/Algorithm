#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	VLL denom;
	LL n;
	LL val;
	char ch = ',';
	while (ch != '\n')
	{
		sll(val);
		denom.pb(val);
		scanf("%c", &ch);
		if (ch != '\n')
			getchar();
	}
	sortv(denom);
	sll(n);
	LL m = denom.size();
	vector<VLL> dp(n + 1, VLL(m + 1, 0));
	for (int i = 1; i <= m; i++)
		dp[0][i] = 1;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 0;
		for (int j = 1; j <= m; j++)
		{
			LL val = dp[i][j - 1];
			if (denom[j - 1] <= i)
				val += dp[i - denom[j - 1]][j];
			dp[i][j] = val;
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}
