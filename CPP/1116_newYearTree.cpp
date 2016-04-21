#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxn = 1 << 20;

int n, m;

vector<int> G[maxn];
int C[maxn], clr[maxn], which[maxn], fin[maxn];
LL T[2 * maxn], L[2 * maxn];
int timer = 0;

void euler(int u = 0, int p = 0)
{
	which[u] = timer++;
	clr[which[u]] = C[u];
	for (auto v: G[u]) 
		if (v != p)
			euler(v, u);
	fin[which[u]] = timer - 1;
}

void build(int nd = 1, int l = 0, int r = maxn - 1)
{
	if (l == r)
	{
		T[nd] = 1ll << clr[l];
		return;
	}
	int mid = (l + r) / 2;
	build(2 * nd, l, mid);
	build(2 * nd + 1, mid + 1, r);
	T[nd] = T[2 * nd] | T[2 * nd + 1];
}

void prop(int nd)
{
	if (not L[nd]) return;
	T[2 * nd] = T[2 * nd + 1] = L[2 * nd] = L[2 * nd + 1] = L[nd];
	L[nd] = 0;
}

void paint(int fl, int fr, int col, int nd = 1, int l = 0, int r = maxn - 1)
{
	if (l > fr or r < fl) return;
	if (l >= fl and r <= fr)
	{
		L[nd] = T[nd] = 1ll << col;
		return;
	}
	prop(nd);
	int mid = (l + r) / 2;
	paint(fl, fr, col, 2 * nd, l, mid);
	paint(fl, fr, col, 2 * nd + 1, mid + 1, r);
	T[nd] = T[2 * nd] | T[2 * nd + 1];
}

LL query(int fl, int fr, int nd = 1, int l = 0, int r = maxn - 1)
{
	if (l > fr or r < fl) return 0;
	if (l >= fl and r <= fr) return T[nd];
	prop(nd);
	int mid = (l + r) / 2;
	return query(fl, fr, 2 * nd, l, mid) | query(fl, fr, 2 * nd + 1, mid + 1, r);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &C[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	euler();
	build();
	for (int i = 0; i < m; i++)
	{
		int t, nd;
		scanf("%d%d", &t, &nd);
		nd = which[nd - 1];
		if (t == 1)
		{
			int col;
			scanf("%d", &col);
			paint(nd, fin[nd], col);
		}
		else
			printf("%d\n", __builtin_popcountll(query(nd, fin[nd])));
	}
	return 0;
}
