#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;
const int logn = 20;
int n, timer;

vector<int> G[maxn];
vector<int> tin(maxn), tout(maxn), L(maxn);
vector<vector<int> > dad(maxn, vector<int> (logn));

void init()
{
	timer = 0;
	for (int i = 1; i <= n; i++)
	{
		G[i].clear(), tin[i] = tout[i] = L[i] = 0;
		for (int j = 0; j < (int) dad[i].size(); j++)
			dad[i][j] = 0;
	}
}

void dfs(int v = 1, int p = 0, int l = 0)
{
	tin[v] = ++timer;
	L[v] = l;
	dad[v][0] = p;
	for (int i = 1; i < logn; i++)
		dad[v][i] = dad[dad[v][i - 1]][i - 1];
	for (auto kid: G[v])
		if (kid != p)
			dfs(kid, v, l + 1);
	tout[v] = ++timer;
}

int anc(int u, int v)
{
	return tin[u] <= tin[v] and tout[v] <= tout[u];
}

int lca(int u, int v)
{
	if (L[u] > L[v])
		swap(u, v);
	int d = L[v] - L[u];
	for (int i = 0; (1 << i) <= d; i++)
		if (d & (1 << i))
			v = dad[v][i];
	if (u == v)
		return u;
	for (int i = logn - 1; i >= 0; i--)
		if (dad[u][i] != dad[v][i])
			u = dad[u][i], v = dad[v][i];
	return dad[u][0];
}

bool cmpByLevel(int u, int v)
{
	return L[u] > L[v];
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		init();
		for (int i = 1; i < n; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs();
		int q;
		scanf("%d", &q);
		while (q--)
		{
			vector<int> foo;
			int k;
			scanf("%d", &k);
			foo.resize(k);
			for (int i = 0; i < k; i++)
				scanf("%d", &foo[i]);
			sort(foo.begin(), foo.end(), cmpByLevel);
			int S = foo[foo.size() - 1];
			int D = foo[0];
			vector<int> A, B;
			for (int i = 0; i < k; i++)
				if (anc(foo[i], D))
					A.push_back(foo[i]);
				else
					B.push_back(foo[i]);
			if (B.size() == 0)
			{
				puts("Yes");
				continue;
			}
			vector<int> C, E;
			int RD = B[0];
			for (int i = 0; i < (int) B.size(); i++)
				if (anc(B[i], RD))
					C.push_back(B[i]);
				else
					E.push_back(B[i]);
			if (E.size())
			{
				puts("No");
				continue;
			}
			int L = lca(D, RD);
			if (anc(S, L) and S != L)
				puts("No");
			else
				puts("Yes");
			/*
			int u = foo[0];
			int v = 0;
			for (int i = 1; i < k; i++)
				if (not anc(foo[i], u))
				{
					v = foo[i];
					break;
				}
			if (v == 0)
			{
				puts("Yes");
				continue;
			}
			bool can = true;
			int L = lca(u, v);
			for (int i = 0; i < k and can; i++)
				if (not anc(foo[i], u) and not anc(foo[i], v))
					can = false;
				else if (not anc(L, foo[i]))
					can = false;
			puts(can? "Yes" : "No");
			*/
		}
	}
	return 0;
}
