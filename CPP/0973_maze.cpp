#include <bits/stdc++.h>

using namespace std;

char G[505][505];
vector<vector<int> > vis(505, vector<int> (505));
int n, m, k;
vector<pair<int, int> > S;

void solve(int r, int c)
{
	if (r < 0 or c < 0 or r >= n or c >= m)
		return;
	if (vis[r][c])
		return;
	vis[r][c] = 1;
	S.push_back(make_pair(r, c));
	solve(r, c + 1), solve(r, c - 1), solve(r - 1, c), solve(r + 1, c);
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		getchar();
		for (int j = 0; j < m; j++)
		{
			cin >> G[i][j];
			if (G[i][j] == '#')
				vis[i][j] = 1;
			else
				vis[i][j] = 0;
		}
	}
	int r = 0, c = 0;
	bool startFound = false;
	for (int i = 0; i < n and not startFound; i++)
		for (int j = 0; j < m and not startFound; j++)
			if (G[i][j] == '.')
				r = i, c = j, startFound = true;
	solve(r, c);
	for (int i = 0, j = S.size() - 1; i < k; i++, j--)
		G[S[j].first][S[j].second] = 'X';
	for (int i = 0; i < n; i++, cout << '\n')
		for (int j = 0; j < m; j++)
			cout << G[i][j];
	return 0;
}
