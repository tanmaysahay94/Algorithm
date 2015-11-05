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
	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	bool yes = true;
	char c = v[0][0];
	for (int i = 0; i < n and yes; i++)
		if (not(v[i][i] == c and v[i][n-i-1] == c))
			yes = false;
	char b = v[0][1];
	for (int i = 0; i < n and yes; i++)
		for (int j = 0; j < n and yes; j++)
		{
			if ((i == j) or (i == n - j - 1))
				continue;
			if (v[i][j] == c)
				yes = false;
			if (v[i][j] != b)
				yes = false;
		}
	if (yes)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
