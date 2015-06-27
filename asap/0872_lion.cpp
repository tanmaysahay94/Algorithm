#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

inline int f(char c)
{
	int ret = c - '0';
	if (ret > 5)
		ret -= 6;
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		char s[111111];
		scanf("%s", s);
		int n = strlen(s);
		vector<vector<LL> > dp(n, vector<LL> (6, 0));
		dp[0][f(s[0])] = 1;
		for (int i = 1; s[i]; i++)
		{
			int dig = f(s[i]);
			dp[i][dig] = 1;
			for (int j = 0; j < 6; j++)
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
			for (int j = 0; j < 6; j++)
			{
				int idx = (10 * j + dig) % 6;
				dp[i][idx] = (dp[i][idx] + dp[i - 1][j]) % mod;
			}
		}
		printf("%lld\n", dp[n - 1][0]);
	}
	return 0;
}
