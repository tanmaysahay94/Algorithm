#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	long long n, m, b, mod;
	cin >> n >> m >> b >> mod;
	long long dp[505][505] = {0};
	// dp[i][j] denotes number of ways to write j lines with i bugs
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		long long bugs;
		cin >> bugs;
		for (long long j = bugs; j <= b; j++)
			for (long long k = 1; k <= m; k++)
			{
				dp[j][k] += dp[j - bugs][k - 1];
				dp[j][k] %= mod;
			}
	}
	long long ans = 0;
	for (int i = 0; i <= b; i++)
	{
		ans += dp[i][m];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}
