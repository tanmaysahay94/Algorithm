#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<int> color;
vector<int> G[111111];
map<int, set<int> > mp;
int n, m;

int main()
{
	optimizeIO();
	cin >> n >> m;
	color = vector<int> (n);
	for (int i = 0; i < n; i++)
	{
		cin >> color[i];
		mp[color[i]].insert(-1);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (int) G[i].size(); j++)
			if (color[i] != color[G[i][j]])
				mp[color[i]].insert(color[G[i][j]]);
	int SZ = (*(mp.begin())).second.size();
	int ans = (*(mp.begin())).first;
	map<int, set<int> >::iterator it;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		int key = (*it).first;
		int sz = (*it).second.size();
		if (sz == SZ)
			ans = min(ans, key);
		else if (sz > SZ)
			SZ = sz, ans = key;
	}
	cout << ans << endl;
	return 0;
}
