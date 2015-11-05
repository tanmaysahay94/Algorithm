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
	vector<long long> v;
	while (t--)
	{
		int n;
		cin >> n;
		v = vector<long long> (n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		long long ans = 0;
		for (int i = 1; i < n; i++)
			ans += v[i];
		if (v[0] < 2)
			ans = -1;
		else
			ans += 2;
		cout << ans << endl;
	}
	return 0;
}
