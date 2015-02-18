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
	int n, m, last = 1;
	cin >> n >> m;
	vector<vector<char> > mp(n, vector<char> (m, '.'));
	for (int i = 0; i < n; i += 2)
		for (int j = 0; j < m; j++)
			mp[i][j] = '#';
	for (int i = 1; i < n; i += 2)
	{
		if (last)
			mp[i][m - 1] = '#';
		else
			mp[i][0] = '#';
		last ^= 1;
	}
	for (int i = 0; i < n; i++, cout << endl)
		for (int j = 0; j < m; j++)
			cout << mp[i][j];
	return 0;
}
