#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n, m;
vector<vector<bool> > vis;
string hor, ver;
int cnt;

void dfs(int i, int j)
{
	if (i < 0 or i >= n or j < 0 or j >= m)
		return;
	if (vis[i][j])
		return;
	cnt++;
	vis[i][j] = true;
	if (hor[i] == '>') dfs(i, j + 1);
	else dfs(i, j - 1);
	if (ver[j] == '^') dfs(i - 1, j);
	else dfs(i + 1, j);
}

int main()
{
	optimizeIO();
	cin >> n >> m;
	cin >> hor >> ver;
	bool flag = true;
	for (int i = 0; i < n and flag; i++)
		for (int j = 0; j < m and flag; j++)
		{
			cnt = 0;
			vis = vector<vector<bool> > (n, vector<bool> (m, false));
			dfs(i, j);
			if (cnt != n * m)
				flag = false;
		}
	if (flag) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
