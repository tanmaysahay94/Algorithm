#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> color;
vector<vector<long long> >dp;
vector<vector<int> > mix;

long long f(int a, int b)
{
	if (dp[a][b] != -1)
		return dp[a][b];
	long long ret = INT_MAX;
	for (int i = a; i < b; i++)
	{
		int smoke = mix[a][i] * mix[i + 1][b];
		smoke += f(a, i) + f(i + 1, b);
		ret = min((int)ret, smoke);
	}
	return dp[a][b] = ret;
}

int main()
{
	while (scanf("%d", &n) == 1)
	{
		color = vector<int> (n);
		mix = vector<vector<int> >(n, vector<int> (n));
		dp = vector<vector<long long> > (n, vector<long long> (n, -1));
		for (int i = 0; i < n; i++)
			scanf("%d", &color[i]), dp[i][i] = 0;
		for (int i = 0; i < n; i++)
		{
			mix[i][i] = color[i];
			for (int j = i + 1; j < n; j++)
				mix[i][j] = (mix[i][j - 1] + color[j]) % 100;
		}
		printf("%lld\n", f(0, n - 1));
	}
	return 0;
}
