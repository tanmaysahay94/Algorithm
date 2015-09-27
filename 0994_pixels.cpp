#include<bits/stdc++.h>

using namespace std;

int n, m, x, y;
int grid[1000][1000], s1[1000], s2[1000], dp[1000][2];
int INF = 1000000000;
string s;

int main()
{
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < m; j++)
			if (s[j] == '#') 
				grid[i][j] = 1;
	}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (grid[j][i]) 
				s1[i]++; 
			else 
				s2[i]++;
	for (int i = 1; i < m; i++)
	{
		s1[i] += s1[i - 1];
		s2[i] += s2[i - 1];
	}
	for (int i = 0; i < m; i++)
		dp[i][0] = dp[i][1] = INF;
	for (int i = 0; i < x; i++) 
		dp[i][0] = dp[i][1] = INF;
	for (int i = x - 1; i < y; i++)
	{
		dp[i][0] = s1[i];
		dp[i][1] = s2[i];
	}
	for (int i = x; i < m; i++)
		for (int j = x - 1; j < y; j++)
			if (i + j < m)
			{
				dp[i + j][0] = min(dp[i + j][0], dp[i - 1][1] + s1[i + j] - s1[i - 1]);
				dp[i + j][1] = min(dp[i + j][1], dp[i - 1][0] + s2[i + j] - s2[i - 1]);
			}
	cout << min(dp[m - 1][0], dp[m - 1][1]) << endl;
	return 0;
}
