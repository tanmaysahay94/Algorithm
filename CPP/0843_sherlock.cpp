#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

const LL mod = 1e9 + 7;

int main()
{
	vector<vector<LL> > c(2001, vector<LL> (2001));
	for (int i = 0; i < 2001; i++)
		c[i][0] = c[i][i] = 1;
	for (int i = 1; i < 2001; i++)
		for (int j = 1; j <= i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%lld\n", c[n + m - 1][n]);
	}
	return 0;
}
