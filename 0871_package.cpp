#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

int main()
{
	optimizeIO();
	LL n, l, m;
	cin >> n >> l >> m;
	vector<LL> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<LL> dp(n);
	dp[0] = 0;
	for (int i = 1; i < n; i++)
		if (v[i] > l)
			dp[i] = i;
		else
		{
			if (v[i - 1] > l)
				dp[i] = i;
			else
				dp[i] = dp[i - 1];
		}
	if (n == 1)
	{
		if (v[0] <= l)
			cout << 1;
		else
			cout << 0;
	}
	LL ans = 0;
	for (int i = 1; i < n; i++)
		if (dp[i] != dp[i - 1])
		{
			if (i - 1 == dp[i - 1])
				continue;
			int len = (i - 1) - dp[i - 1] + 1;
			if (len >= m)
			{
				len = len - m + 1;
				ans += len;
			}
		}
	int len = (n - 1) - dp[n - 1] + 1;
	if (len >= m)
	{
		len = len - m + 1;
		ans += len;
	}
	cout << ans;
	return 0;
}
