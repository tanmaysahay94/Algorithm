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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<long long> > v(n, vector<long long> (n));
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= i; j++)
				cin >> v[i][j];
		for (int i = n - 2; i >= 0; i--)
			for (int j = 0; j <= i; j++)
				v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
		cout << v[0][0] << endl;
	}
	return 0;
}
