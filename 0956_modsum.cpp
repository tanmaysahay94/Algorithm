#include <bits/stdc++.h>

using namespace std;

set<int> S;

int main()
{
	long long n, m;
	cin >> n >> m;
	if (n > m)
	{
		cout << "YES";
		return 0;
	}
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		v[i] %= m;
	}
	if (n <= m)
	{
		bool possible = false;
		long long dp[2][1005];
		memset(dp, 0, sizeof(dp));
		int idx = 1;
		dp[0][v[0]] = 1;
		S.insert(v[0]);
		for (int i = 1; i < n and not possible; i++, idx ^= 1)
		{
			int prev = idx ^ 1;
			for (int j = 0; j < m; j++)
				dp[idx][j] = dp[prev][j];
			dp[idx][v[i]] = 1;
			S.insert(v[i]);
			set<long long> foo;
			for (auto s: S)
			{
				int sum = (s + v[i]) % m;
				foo.insert(sum);
				dp[idx][sum] = 1;
			}
			for (auto s: foo)
				S.insert(s);
			if (S.count(0))
				possible = true;
		}
		if (S.count(0))
			possible = true;
		if (possible)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}
