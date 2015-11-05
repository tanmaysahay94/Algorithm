#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	const int mod = 1e9 + 7;
	long long ans = 1;
	vector<string> s(n);
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int col = 0; col < m; col++)
	{
		set<char> f;
		for (int row = 0; row < n; row++)
			f.insert(s[row][col]);
		long long val = f.size();
		ans = (ans * val) % mod;
	}
	cout << ans;
	return 0;
}
