#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int n;
vector<int> G[3333];
vector<int> dad;
vector<int> vis;
vector<int> D;
vector<int> inCycle;
vector<int> ans;
int start;

void generateCycle(int node)
{
	while (node != start)
	{
		inCycle.push_back(node);
		node = dad[node];
	}
}

void getDad(int node, int prev, int depth)
{
	if (start != -1)
		return;
	if (vis[node])
	{
		if (depth - D[node] > 2)
		{
			start = node;
			inCycle.push_back(start);
			generateCycle(prev);
		}
		return;
	}
	vis[node] = 1;
	dad[node] = prev;
	D[node] = depth;
	for (int i = 0; i < (int) G[node].size(); i++)
		getDad(G[node][i], node, depth + 1);
}

int main()
{
	optimizeIO();
	start = -1;
	cin >> n;
	dad = vector<int> (n, -1);
	ans = vector<int> (n, 4444);
	vis = vector<int> (n);
	D = vector<int> (n);
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	getDad(0, -1, 0);
	for (int i = 0; i < n; i++)
		vis[i] = 0;
	queue<int> bfs;
	for (int i = 0; i < (int) inCycle.size(); i++)
		ans[inCycle[i]] = 0, vis[inCycle[i]] = 1, bfs.push(inCycle[i]);
	while (not bfs.empty())
	{
		int rem = bfs.front();
		bfs.pop();
		for (int i = 0; i < (int) G[rem].size(); i++)
			if (!vis[G[rem][i]])
			{
				vis[G[rem][i]] = 1;
				bfs.push(G[rem][i]);
				ans[G[rem][i]] = min(ans[rem] + 1, ans[G[rem][i]]);
			}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}
