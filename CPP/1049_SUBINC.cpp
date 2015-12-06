#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);
		vector<int> dp(n);
		dp[0] = 0;
		for (int i = 1; i < n; i++)
			if (v[i] >= v[i - 1])
				dp[i] = dp[i - 1];
			else
				dp[i] = i;
		long long ans = 0;
		for (int i = 0; i < n; i++)
			ans += ((long long) i - (long long) dp[i] + 1LL);
		printf("%lld\n", ans);
	}
	return 0;
}
