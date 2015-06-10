#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	int n, m;
	cin >> n >> m;
	int a[111][111], c[111][111];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			if (s[j] == 'W')
				a[i][j] = 1;
			else
				a[i][j] = -1;
			c[i][j] = 0;
		}
	}
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) 
			if (c[i][j] != a[i][j])
			{
				ans++;
				int d = a[i][j] - c[i][j];
				for (int ii = i; ii >= 0; ii--)
					for (int jj = j; jj >= 0; jj--)
						c[ii][jj] += d;
			}
	cout << ans << endl;
	return 0;
}
