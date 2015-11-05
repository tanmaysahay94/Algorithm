#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n, m;
vector<vector<int> > v;

int f(int n)
{
	if (n & 1)
		return n;
	bool match = true;
	int cnt = 1;
	for (int i = n/2 - 1; i >= 0 and match; i--, cnt++)
		for (int j = 0; j < m and match; j++)
			if (v[i][j] != v[i + 2 * cnt - 1][j])
				match = false;
	if (match)
		return f(n/2);
	return n;
}

int main()
{
	optimizeIO();
	cin >> n >> m;
	v = vector<vector<int> > (n, vector<int> (m));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> v[i][j];
	cout << f(n) << endl;
	return 0;
}
