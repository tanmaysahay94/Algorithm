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
	int t, n;
	vector<pair<int, int> > check;
	vector<int> v;
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n;
		v.resize(n);
		check = vector<pair<int, int> > (n, make_pair(0, 0));
		for (int i = 0; i < n; i++)
			cin >> v[i];
		for (int i = 1; i < n; i++)
			if (v[i - 1] != v[i])
				check[i - 1].first = 1, check[i].second = 1;
		for (int i = 0; i < n; i++)
			if (check[i].first or check[i].second)
				ans++;
		cout << ans << endl;
	}
	return 0;
}
