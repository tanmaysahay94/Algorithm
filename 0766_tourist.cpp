#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long f(vector<pair<long long, long long> >& v, int i, int j)
{
	long long dd = abs(v[i].first - v[j].first);
	long long a = v[i].second;
	long long b = v[j].second;
	if (a > b) swap(a, b);
	long long tmp = dd - (b - a);
	return b + (tmp/2);
}

int main()
{
	optimizeIO();
	long long n, m;
	cin >> n >> m;
	vector<pair<long long, long long> > v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end());
	bool possible = true;
	for (int i = 1; i < m and possible; i++)
		if (v[i].first - v[i - 1].first < abs(v[i].second - v[i - 1].second))
			possible = false;
	if (not possible) cout << "IMPOSSIBLE";
	else
	{
		long long ans = -1;
		for (int i = 1; i < m; i++)
			ans = max(ans, f(v, i, i - 1));
		if (v[0].first != 0) ans = max(ans, v[0].second + v[0].first - 1);
		if (v[m - 1].first != n) ans = max(ans, v[m - 1].second + (n - v[m - 1].first));
		cout << ans << endl;
	}
	return 0;
}
