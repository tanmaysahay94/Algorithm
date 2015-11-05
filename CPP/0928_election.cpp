#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long solve(vector<long long>& v)
{
	long long idx = -1;
	long long val = -1;
	for (int i = (int) v.size() - 1; i >= 0; i--)
		if (v[i] >= val)
			val = v[i], idx = i;
	return idx + 1;
}

int main()
{
	optimizeIO();
	int n, m;
	cin >> n >> m;
	vector<vector<long long> > v(m, vector<long long> (n));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> v[i][j];
	vector<long long> cnt(m);
	for (int i = 0; i < m; i++)
		cnt[i] = solve(v[i]);
	map<long long, long long> mp;
	for (int i = 0; i < m; i++)
		mp[cnt[i]]++;
	long long idx = -1;
	long long val = -1;
	for (auto it: mp)
		if (it.second > val)
			val = it.second, idx = it.first;
		else if (it.second == val and it.first < idx)
			idx = it.first;
	cout << idx;
	return 0;
}
