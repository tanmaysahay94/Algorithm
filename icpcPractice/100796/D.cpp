#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int maxn = 505;
const int maxm = 505;

int vis[maxn][maxm];
vector<string> grid;
queue<pair<pair<int, int>, int> >q;
LL n, m, a, b;

bool isValid(int i, int j)
{
	if (i < 0 or i >= m) return false;
	if (j < 0 or j >= n) return false;
	return vis[i][j] == 0;
}

void put(int i, int j, int d)
{
	q.push(make_pair(make_pair(i, j), d));
	vis[i][j] = 1;
}

int prod(int a, int b, int k)
{
	return a * (k / 2) + b * (k - (k / 2));
}

int main()
{
	memset(vis, 0, sizeof(vis));
	cin >> n >> m >> a >> b;
	for (int i = 0; i < m; i++)
	{
		string row;
		cin >> row;
		grid.push_back(row);
		for (int j = 0; j < (int) row.size(); j++)
			if (grid[i][j] == '#')
				vis[i][j] = 1;
	}
	if (vis[0][0] or vis[m - 1][n - 1])
	{
		cout << "IMPOSSIBLE";
		return 0;
	}
	put(0, 0, 0);
	bool found = false;
	int finalDist;
	while (q.size())
	{
		pair<pair<int, int>, int> justRem = q.front();
		q.pop();
		pair<int, int> loc = justRem.first;
		int dist = justRem.second;
		int i = loc.first, j = loc.second;
		if (i == m - 1 and j == n - 1)
		{
			found = true;
			finalDist = dist;
			break;
		}
		if (isValid(i, j - 1)) put(i, j - 1, dist + 1);
		if (isValid(i, j + 1)) put(i, j + 1, dist + 1);
		if (isValid(i - 1, j)) put(i - 1, j, dist + 1);
		if (isValid(i + 1, j)) put(i + 1, j, dist + 1);
	}
	if (found)
	{
		cout << (finalDist / 2) * a + (finalDist - finalDist / 2) * b;
		// cout << min(prod(a, b, finalDist), prod(b, a, finalDist));
	}
	else
		cout << "IMPOSSIBLE";
	return 0;
}
