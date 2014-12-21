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

class edge
{
	public:
	LL a, b, old, rep, diff, count;
	edge(LL a_, LL b_, LL old_, LL rep_): a(a_), b(b_), old(old_), rep(rep_), diff(rep_-old_), count(0LL) {}
};

struct cmp
{
	bool operator() (edge p, edge q)
	{
		return p.diff*p.count < q.diff*q.count;
	}
};

vector<edge> graph[111111], eList;
vector<int> visited;

LL dfs(LL start, LL n)
{
	LL children = 1;
	visited[start] = 1;
	for (int i = 0; i < (int) graph[start].size(); i++)
		if (!visited[graph[start][i].b])
		{
			LL val = dfs(graph[start][i].b, n);
			graph[start][i].count = val * (n - val);
			eList.pb(graph[start][i]);
			children += val;
		}
	return children;
}

int main()
{
	int t;
	si(t);
	while (t--)
	{
		eList = vector<edge> ();
		LL n, k, x, y, a, b;
		sll(n); sll(k);
		visited = VI (n);
		for (int i = 0; i < n; i++)
			visited[i] = 0;
		for (int i = 1; i <= n - 1; i++)
		{
			sll(x); sll(y); sll(a); sll(b);
			x--; y--;
			graph[x].pb(edge(x, y, a, b));
			graph[y].pb(edge(y, x, a, b));
		}
//		LL start = 0;
//		for (; start < n and graph[start].size() == 1; start++);
		dfs(0, n);
		sort(eList.begin(), eList.end(), cmp());
		LL ans = 0;
		for (int i = 0; i < (int) eList.size(); i++)
			if (i < k and eList[i].diff < 0)
				ans += eList[i].count*eList[i].rep;
			else
				ans += eList[i].count*eList[i].old;
		printf("%lld\n", ans);
		for (int i = 0; i < n; i++)
			graph[i].clear();
	}
	return 0;
}
