#include <bits/stdc++.h>

using namespace std;

int main()
{
	int happy[3005][3];
	int dp[2][2];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> happy[i][0];
	for (int i = 0; i < n; i++)
		cin >> happy[i][1];
	for (int i = 0; i < n; i++)
		cin >> happy[i][2];
	int curr = 0;
	dp[0][0] = happy[0][0];
	dp[0][1] = happy[0][1];
	for (int i = 2; i <= n; i++)
	{
		dp[!curr][0] = max(dp[curr][0] + happy[i - 1][1], dp[curr][1] + happy[i - 1][0]);
		dp[!curr][1] = max(dp[curr][0] + happy[i - 1][2], dp[curr][1] + happy[i - 1][1]);
		curr = !curr;
	}
	cout << dp[curr][0];
	return 0;
}
