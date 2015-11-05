#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long mod = 1e9 + 7;

int main()
{
	optimizeIO();
	long long v[505][505] = {0};
	for (int i = 0; i < 505; i++)
		v[i][0] = v[0][i] = 1;
	for (int i = 1; i < 505; i++)
		for (int j = 1; j < 505; j++)
			v[i][j] = (v[i-1][j] + v[i][j-1]) % mod;
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		cout << v[n][m] << endl;
	}
	return 0;
}
