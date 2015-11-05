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
		int n, d;
		cin >> n >> d;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.rbegin(), v.rend());
		long long ans = 0;
		int i = 0;
		while (i < n)
		{
			int j = i + 1;
			if (j < n and v[i] - v[j] < d)
			{
				ans += v[i] + v[j];
				i = j + 1;
			}
			else
				i = j;
		}
		cout << ans << '\n';
	}
	return 0;
}
