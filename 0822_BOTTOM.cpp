#include <bits/stdc++.h>

using namespace std;

vector<int> G[5555], GR[5555];
stack<int> S;
vector<int> vis(5555);
vector<int> component(5555);
vector<int> solution(5555);

void dfs1(int v)
{
	if (vis[v]) return;
	vis[v] = 1;
	for (int i = 0; i < (int) G[v].size(); i++)
		dfs1(G[v][i]);
	S.push(v);
}

void dfs2(int v, int c)
{
	if (vis[v]) return;
	vis[v] = 1;
	component[v] = c;
	for (int i = 0; i < (int) GR[v].size(); i++)
		dfs2(GR[v][i], c);
}

int main()
{
	int n;
	while (scanf("%d", &n)) 
	{
		if (not n) break;
		for (int i = 0; i <= n; i++) solution[i] = 0, component[i] = 0, vis[i] = 0, G[i].clear(), GR[i].clear();
		int m, u, v;
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			GR[v].push_back(u);
		}
		for (int i = 1; i <= n; i++) if (not vis[i]) dfs1(i);
		for (int i = 0; i <= n; i++) vis[i] = 0;
		int cnt = 1;
		while (!S.empty())
		{
			int v = S.top(); S.pop();
			if (vis[v]) continue;
			dfs2(v, cnt);
			solution[cnt++] = 1;
		}
		for (int i = 1; i <= n; i++) for (int j = 0; j < (int) G[i].size(); j++) if (component[i] != component[G[i][j]]) {solution[component[i]] = 0; break;}
		for (int i = 1; i <= n; i++) if (solution[component[i]]) printf("%d ", i);
		printf("\n");
	}
	return 0;
}
