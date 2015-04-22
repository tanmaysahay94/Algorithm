#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int level[2222];
vector<int> G[2222];
vector<int> roots;
int tmp;

void dfs(int node, int depth)
{
	tmp = max(tmp, depth);
	level[node] = depth;
	for (int i = 0; i < (int) G[node].size(); i++)
		dfs(G[node][i], depth + 1);
}

int main()
{
	optimizeIO();
	int n, ans(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int parent;
		cin >> parent;
		if (parent == - 1)
		{
			level[i] = 1;
			roots.push_back(i);
		}
		else
			G[parent].push_back(i);
	}
	for (int i = 0; i < (int) roots.size(); i++)
	{
		tmp = 0;
		dfs(roots[i], 1);
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}
