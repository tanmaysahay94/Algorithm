#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int n;
	scanf("%d", &n);
	vector<LL> dp(n + 1);
	vector<int> v = {1, 2, 5, 10, 20, 50, 100};
	dp[0] = 1;
	for (int i = 0; i < (int) v.size(); i++)
	{
		if (v[i] > n)
			break;
		for (int j = v[i]; j <= n; j++)
			dp[j] += dp[j - v[i]];
	}
	cout << dp[n];
	return 0;
}
