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
		int ans = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			int v;
			cin >> v;
			if ((n & 1) and (i & 1))
				ans ^= v;
		}
		cout << ans << '\n';
	}
	return 0;
}
