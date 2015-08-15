#include <bits/stdc++.h>

using namespace std;

const int maxn = 500005;

int n, m, id = 1;
int H[maxn], HR[maxn], L[maxn], E[maxn];
vector<int> G[maxn], LH[maxn];
char s[maxn];

void dfs(int v = 1, int l = 1)
{
	H[v] = id;
	HR[id] = v;
	L[v] = l;
	LH[l].push_back(id);
	id++;
	if (not G[v].size())
	{
		E[v] = H[v];
		return;
	}
	for (auto u: G[v])
		dfs(u, l + 1);
	E[v] = id - 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= n; i++)
	{
		int p;
		scanf("%d", &p);
		G[p].push_back(i);
	}
	dfs();
	scanf("%s", s);
	return 0;
}
