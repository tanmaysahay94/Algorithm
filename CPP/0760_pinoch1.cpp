#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<long long> v;

int main()
{
	optimizeIO();
	long long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		v = vector<long long> (n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		int ans = 0;
		for (int i = 1; i < n; i++)
			if (v[i] != v[i - 1])
				ans++;
		cout << ans << endl;
	}
	return 0;
}
