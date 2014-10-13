#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL t;
	SLL(t);
	while (t--)
	{
		string a, b;
		cin >> a >> b;
		LL p = a.length(), q = b.length();
		vector< VLL > dp(p + 1, VLL (q + 1, 0));
		for (int i = 1; i <= p; i++)
			dp[i][0] = i;
		for (int i = 1; i <= q; i++)
			dp[0][i] = i;
		for (int i = 1; i <= p; i++)
			for (int j = 1; j <= q; j++)
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1];
				else
					dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
		cout << dp[p][q] << endl;
	}
	return 0;
}
