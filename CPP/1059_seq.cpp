#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int> > pos(n + 1);
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		pos[x].push_back(i);
	}
	bool f = false;
	vector<int> ans(m);
	for (int i = 0; i < m; i++)
	{
		int x;
		cin >> x;
		if (pos[x].size() == 1)
			ans[i] = pos[x][0] + 1;
		else if (pos[x].size() == 0)
		{
			cout << "Impossible";
			return 0;
		}
		else
			f = true;
	}
	if (f)
		cout << "Ambiguity" << endl;
	else
	{
		cout << "Possible" << endl;
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << endl;
	}
	return 0;
}
