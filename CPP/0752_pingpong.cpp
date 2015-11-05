#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n;
vector<pair<int, int> > interval;
vector<int> G[111];
vector<int> vis;

bool check(int a, int b)
{
	if (a == b)
		return true;
	if (vis[a])
		return false;
	vis[a] = 1;
	bool found = false;
	for (int i = 0; i < (int) G[a].size(); i++)
		found = found or check(G[a][i], b);
	return found;
}

int main()
{
	optimizeIO();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1)
		{
			vis.push_back(0);
			interval.push_back(make_pair(a, b));
			int sz = interval.size();
			for (int j = 0; j < sz - 1; j++)
			{
				int x = interval[j].first;
				int y = interval[j].second;
				if ((a < x and x < b) or (a < y and y < b))
					G[j].push_back(sz - 1);
				if ((x < a and a < y) or (x < b and b < y))
					G[sz - 1].push_back(j);
			}
		}
		else
		{
			for (int i = 0; i < (int) vis.size(); i++)
				vis[i] = 0;
			a--; b--;
			if (check(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
