#include <bits/stdc++.h>

using namespace std;

set<pair<int, pair<int, int> > > S;

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= 2 * n; i++)
		for (int j = 1; j < i; j++)
		{
			int val;
			cin >> val;
			S.insert(make_pair(val, make_pair(i, j)));
		}
	vector<int> ans(2 * n + 1);
	set<int> toAllot;
	for (int i = 1; i <= 2 * n; i++)
		toAllot.insert(i);
	for (auto it = S.rbegin(); it != S.rend(); it++)
	{
		int a = (*it).second.first;
		int b = (*it).second.second;
		if (toAllot.count(a) and toAllot.count(b))
			ans[a] = b, ans[b] = a, toAllot.erase(a), toAllot.erase(b);
	}
	for (int i = 1; i <= 2 * n; i++)
		cout << ans[i] << ' ';
	return 0;
}
