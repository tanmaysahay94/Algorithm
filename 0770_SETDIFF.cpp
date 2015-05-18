#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long mod = 1e9 + 7;

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<long long> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		long long a(0), b(0);
		for (int i = 0; i < n; i++)
		{
			a = (2 * a + v[i]) % mod;
			b = (2 * b + v[n - i - 1]) % mod;
		}
		cout << (b - a + mod) % mod << endl;
	}
	return 0;
}
