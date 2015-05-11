#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

void solve()
{
	int n, k;
	string s;
	cin >> n >> k >> s;
	int ans = -1;
	for (int i = 0; i <= n - k; i++)
	{
		int tmp = 1;
		for (int j = i; j < i + k; j++)
			tmp *= s[j] - '0';
		ans = max(tmp, ans);
	}
	cout << ans << endl;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
