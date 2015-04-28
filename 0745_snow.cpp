#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

vector<pair<int, int> > v;
vector<bool> vis;
int n;

void dfs(int idx)
{
	if (vis[idx])
		return;
	vis[idx] = true;
	for (int i = 0; i < n; i++)
		if (i != idx && (v[i].first == v[idx].first || v[i].second == v[idx].second))
			dfs(i);
}

int main()
{
	optimizeIO();
	int cnt(0);
	cin >> n;
	v.resize(n);
	vis = vector<bool> (n, false);
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;
	for (int i = 0; i < n; i++)
		if (not vis[i])
		{
			dfs(i);
			cnt++;
		}
	cout << cnt - 1 << endl;
	return 0;
}
