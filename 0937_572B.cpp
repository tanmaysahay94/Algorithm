#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, s;
	cin >> n >> s;
	map<int, int> buy, sell;
	string dir;
	int p, q;
	for (int i = 0; i < n; i++)
	{
		cin >> dir >> p >> q;
		if (dir[0] == 'B')
			buy[p] += q;
		else
			sell[p] += q;
	}
	int cnt = 0;
	vector<pair<int, int> > v;
	for (auto it = sell.begin(); cnt < s and it != sell.end(); it++, cnt++)
		v.push_back(make_pair(it->first, it->second));
	sort(v.rbegin(), v.rend());
	for (int i = 0; i < (int) v.size(); i++)
		cout << "S " << v[i].first << ' ' << v[i].second << '\n';
	cnt = 0;
	for (auto it = buy.rbegin(); cnt < s and it != buy.rend(); it++, cnt++)
		cout << "B " << it->first << ' ' << it->second << '\n';
	return 0;
}
