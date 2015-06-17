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
	int n;
	cin >> n;
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i;
	}
	sort(v.begin(), v.end(), greater<pair<int, int> >());
	vector<int> ans(n);
	ans[v[0].second] = 1;
	for (int i = 1; i < n; i++)
		if (v[i].first == v[i - 1].first)
			ans[v[i].second] = ans[v[i - 1].second];
		else
			ans[v[i].second] = i + 1;
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
