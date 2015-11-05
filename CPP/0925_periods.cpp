#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

map<int, vector<int> > loc;

bool foo(vector<int>& v)
{
	if ((int) v.size() <= 2)s
		return true;
	int d = v[1] - v[0];
	for (int i = 2; i < (int) v.size(); i++)
		if (d != v[i] - v[i - 1])
			return false;
	return true;
}

int bar(vector<int>& v)
{
	if ((int) v.size() == 1)
		return 0;
	return v[1] - v[0];
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		loc[val].push_back(i);
	}
	vector<pair<int, int> > ans;
	for (auto l: loc)
		if (foo(l.second))
			ans.push_back({l.first, bar(l.second)});
	cout << ans.size() << '\n';
	for (auto a: ans)
		cout << a.first << ' ' << a.second << '\n';
	return 0;
}
