#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int parent[200000], word[200000], dp[200000][200];

int ancestor(int i)
{
	if (parent[i] != i)
		parent[i] = ancestor(parent[i]);
	return parent[i];
}

void merge(int i, int j)
{
	i = ancestor(i);
	j = ancestor(j);
	if (i != j)
		parent[i] = j;
}

int main()
{
	optimizeIO();
	int t, n, m, k, from, to;
	cin >> t;
	while (t--)
	{
		int foo = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++)
			parent[i] = i;
		while (m--)
		{
			cin >> from >> to;
			from--, to--;
			merge(from, to);
		}
		for (int i = 0; i < n; i++)
			parent[i] = ancestor(i);
		for (int i = 0; i < k; i++)
		{
			cin >> word[i];
			word[i]--;
		}
		for (int i = 0; i < k; i++)
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = k + 1;
				if (j != 0)
					dp[i][j] = min(dp[i][j], dp[i][j - 1]);
				if (parent[word[i]] == parent[j])
				{
					foo = 1;
					if (word[i] == j)
						foo = 0;
					int bar = foo;
					if (i != 0)
						bar += dp[i - 1][j];
					dp[i][j] = min(dp[i][j], bar);
				}
			}
		if (dp[k - 1][n - 1] == k + 1)
			dp[k - 1][n - 1] = -1;
		cout << dp[k - 1][n - 1] << '\n';
	}
	return 0;
}
