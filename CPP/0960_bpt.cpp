#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int> > ans;
	if (n > m)
		for (int x = n, y = m; y >= 0; x--, y--)
			ans.push_back(make_pair(x, y));
	else
		for (int x = 0, y = m; x <= n; x++, y--)
			ans.push_back(make_pair(x, y));
	cout << ans.size() << endl;
	for (auto pt: ans)
		cout << pt.first << ' ' << pt.second << endl;
	return 0;
}
