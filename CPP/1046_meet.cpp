#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<LL> > a(n + 2, vector<LL> (m + 2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	vector<vector<LL> > dp1, dp2, dp3, dp4;
	dp1 = dp2 = dp3 = dp4 = a;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp1[i][j] = a[i][j] + max(dp1[i - 1][j], dp1[i][j - 1]);
	for (int i = n; i >= 1; i--)
		for (int j = m; j >= 1; j--)
			dp2[i][j] = a[i][j] + max(dp2[i + 1][j], dp2[i][j + 1]);
	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= m; j++)
			dp3[i][j] = a[i][j] + max(dp3[i][j - 1], dp3[i + 1][j]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= 1; j--)
			dp4[i][j] = a[i][j] + max(dp4[i - 1][j], dp4[i][j + 1]);
	LL ans = 0;
	for (int i = 2; i < n; i++)
		for (int j = 2; j < m; j++)
			ans = max(ans, max(dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j], dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]));
	cout << ans;
	return 0;
}
