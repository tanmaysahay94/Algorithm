#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

map<long long, long long> dp;

long long solve(long long val)
{
	if (val == 0)
		return 0;
	if (dp[val])
		return dp[val];
	long long temp = solve(val/2) + solve(val/3) + solve(val/4);
	if (temp > val)
		dp[val] = temp;
	else
		dp[val] = val;
	return dp[val];
}

int main()
{
	optimizeIO();
	long long val;
	while (scanf("%lld", &val) != EOF)
		cout << solve(val) << endl;
	return 0;
}
