#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

vector<vector<long long> > dp;

int main()
{
	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; T++)
	{
		long long my, his;
		scanf("%lld-%lld", &my, &his);
		if (his == 0)
		{
			int v1 = 1, v2 = 1;
			printf("Case #%d: %lld %lld\n", T, v1, v2);
			continue;
		}
		dp = vector<vector<long long> > (my + 1, vector<long long> (my + 1, 0LL));
		for (int row = 1; row <= my; row++)
			dp[row][0] = 1;
		for (int col = 1; col <= his; col++)
			for (int row = col + 1; row <= my; row++)
				dp[row][col] = (dp[row - 1][col] + dp[row][col - 1]) % mod;
		long long v1 = dp[my][his];
		dp = vector<vector<long long> > (my + 1, vector<long long> (my + 1, 0LL));
		for (int col = 0; col <= his; col++)
			dp[0][col] = 1;
		for (int col = 1; col <= his; col++)
			for (int row = 1; row <= col; row++)
				dp[row][col] = (dp[row - 1][col] + dp[row][col - 1]) % mod;
		long long v2 = dp[his - 1][his];
		printf("Case #%d: %lld %lld\n", T, v1, v2);
	}
	return 0;
}
