#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e8;
const LL N = 105;
const LL K = 15;

LL dp[N][N][K][K];
LL n1, n2, k1, k2;

LL solve(LL N1, LL N2, LL K1, LL K2)
{
	if (N1 < 0 or N2 < 0 or K1 < 0 or K2 < 0)
		return 0;
	if (N1 == 0 and N2 == 0)
		return 1;
	if (dp[N1][N2][K1][K2] != -1)
		return dp[N1][N2][K1][K2];
	return dp[N1][N2][K1][K2] = (solve(N1 - 1, N2, K1 - 1, k2) + solve(N1, N2 - 1, k1, K2 - 1)) % mod;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n1 >> n2 >> k1 >> k2;
	cout << solve(n1, n2, k1, k2);
	return 0;
}
