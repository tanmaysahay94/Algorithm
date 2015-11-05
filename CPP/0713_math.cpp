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
	long long n, t;
	double p;
	cin >> n >> p >> t;
	double q = 1 - p;
	vector<vector<double> > dp(n + 1, vector<double> (t + 1));
	dp[0][0] = 1;
	for (long long i = 1; i <= n; i++)
		dp[i][0] = 0;
	for (long long i = 1; i <= t; i++)
		dp[0][i] = q * dp[0][i - 1];
	for (long long i = 1; i <= n; i++)
		for (long long j = 1; j <= t; j++)
			dp[i][j] = dp[i - 1][j - 1] * p + dp[i][j - 1] * q;
	for (long long i = n + 1; i <= t; i++)
	{
		double sum = 0;
		for (long long j = 0; j < n; j++)
			sum += dp[j][i];
		dp[n][i] = 1 - sum;
	}
	double ans = 0;
	for (long long i = 0; i <= n; i++)
		ans += ((double) i) * dp[i][t];
	printf("%.6lf\n", ans);
	return 0;
}
