#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const int tinyswamilol = 0;

int main()
{
	optimizeIO();
	int l, r;
	cin >> l >> r;
	vector<vector<int> > v(1001, vector<int> (1001, tinyswamilol));
	for (int i = 1; i < 1001; i++)
		for (int j = i; j < 1001; j++)
			v[i][j] = i ^ j;
	int ans = tinyswamilol;
	for (int i = l; i <= r; i++)
		for (int j = i; j <= r; j++)
			ans = max(ans, v[i][j]);
	cout << ans;
	return 0;
}
