#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e8;
const LL lim = 205;

int main()
{
	LL n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	LL dp1[lim][lim], dp2[lim][lim];
	memset(dp1, 0, sizeof(dp1));
	memset(dp2, 0, sizeof(dp2));
	dp1[0][0] = dp2[0][0] = 1;
	for (int i = 1; i <= n1 + n2; i++)
		for (int j = 0; j <= i; j++)
		{
			for (int k = 1; k <= k1; k++)
			{
				if (k > j)
					break;
				dp1[j][i - j] = (dp1[j][i - j] + dp2[j - k][i - j]) % mod;
			}
			for (int k = 1; k <= k2; k++)
			{
				if (k > i - j)
					break;
				dp2[j][i - j] = (dp2[j][i - j] + dp1[j][i - j - k]) % mod;
			}
		}
	cout << (dp1[n1][n2] + dp2[n1][n2]) % mod;
	return 0;
}
