#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL n, k, b, x, y, q, a, p;
VLL prod, visited;
vector<VLL> ans, graph;

int dfs1(int city, int val)
{
	int sz = graph[city].size();
	int ret = INT_MAX;
	for (int i = 0; i < sz; i++)
	{
		int neighbour = graph[city][i];
		if (!visited[neighbour])
		{
			visited[neighbour] = 1;
			ret = min(ret, dfs1(neighbour, val));
		}
	}
	if (prod[city] == val)
		ret = min(ret, city);
	return ans[city][val] = ret;
}

int dfs2(int city, int val, int ret)
{
	visited[city] = 1;
	int sz = graph[city].size();
	if (ans[city][val] == INT_MAX)
		ans[city][val] = ret;
	for (int i = 0; i < sz; i++)
	{
		int neighbour = graph[city][i];
		if (!visited[neighbour])
			dfs2(neighbour, val, ans[city][val]);
	}
	return 0;
}

int main()
{
	sll(n); sll(k); sll(b); b--;
	ans = vector<VLL> (n, VLL (k));
	graph = vector<VLL> (n);
	prod = VLL(n);
	visited = VLL(n, 0);
	for (int i = 0; i < n - 1; i++)
	{
		sll(x); sll(y);
		x--; y--;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	for (int i = 0; i < n; i++)
	{
		sll(prod[i]);
		prod[i]--;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			ans[i][j] = INT_MAX;
	for (int i = 0; i < k; i++)
	{
		dfs1(b, i);
		if (ans[b][i] == INT_MAX)
			ans[b][i] = -2;
		for (int j = 0; j < n; j++)
			visited[j] = 0;
		dfs2(b, i, ans[b][i]);
		for (int j = 0; j < n; j++)
			visited[j] = 0;
	}
	sll(q);
	for (int i = 0; i < q; i++)
	{
		sll(a); sll(p);
		a--; p--;
		printf("%lld\n", ans[a][p] + 1);
	}
	return 0;
}
