#include <bits/stdc++.h>

using namespace std;

int n;

const int maxn = 1e5 + 5;

vector<int> G[maxn];
int init[maxn], goal[maxn], vis[maxn];
vector<int> ans;

void dfs(int v = 1, int o = 0, int e = 0, int l = 1)
{
	if (vis[v])
		return;
	vis[v] = 1;
	int curr = init[v];
	if (l & 1)
	{
		curr = init[v] ^ o;
		if (curr != goal[v])
			o ^= 1, ans.push_back(v);
	}
	else
	{
		curr = init[v] ^ e;
		if (curr != goal[v])
			e ^= 1, ans.push_back(v);
	}
	for (auto u: G[v])
		dfs(u, o, e, l + 1);
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", &init[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &goal[i]);
	dfs();
	printf("%d\n", (int) ans.size());
	for (auto foo: ans)
		printf("%d\n", foo);
	return 0;
}
