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
	char c[55][55];
	char tc[] = "face";
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];
	if (n < 2 or m < 2)
	{
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 0; i + 1 < n; i++)
	{
		for (int j = 0; j + 1 < m; j++)
		{
			int p[4] = {0};
			for (int k = 0; k < 4; k++)
			{
				if (c[i][j] == tc[k])
					p[k] = 1;
				if (c[i][j + 1] == tc[k])
					p[k] = 1;
				if (c[i + 1][j] == tc[k])
					p[k] = 1;
				if (c[i + 1][j + 1] == tc[k])
					p[k] = 1;
			}
			bool yes = true;
			for (int i = 0; i < 4; i++)
				if (p[i] == 0)
					yes = false;
			if (yes)
				ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
