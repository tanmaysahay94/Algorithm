#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

class solution {
	public:
		vector<VI> graph;
		VI cost;
		solution(vector<VI>& G, VI& C): graph(G), cost(C) {}
		int dfs(int root)
		{
			if (graph[root].size() == 0)
			{
				cost[root] = 1;
				return cost[root];
			}
			set<int> visited;
			for (int i = 0; i < (int) graph[root].size(); i++)
			{
				int ret = dfs(graph[root][i]);
				visited.insert(ret);
			}
			VI vis; vis.pb(0);
			set<int>::iterator it;
			for (it = visited.begin(); it != visited.end(); it++)
				vis.pb(*it);
			sortv(vis);
			int i;
			for (i = 1; i < (int) vis.size(); i++)
				if (vis[i] - vis[i-1] > 1)
				{
					cost[root] = vis[i-1] + 1;
					break;
				}
			if (i == (int) vis.size())
				cost[root] = vis[i-1] + 1;
			return cost[root];
		}
		LL getsol()
		{
			LL ans = 0;
			for (int i = 1; i < (int) cost.size(); i++)
				ans += cost[i];
			return ans;
		}
};

int main()
{
	int t;
	si(t);
	for (int test = 1; test <= t; test++)
	{
		int n, root, boss;
		si(n);
		si(root);
		vector<VI> graph(n+1);
		for (int i = 2; i <= n; i++)
		{
			si(boss);
			graph[boss].pb(i);
		}
		VI cost(n+1, 0);
		solution soln(graph, cost);
		soln.dfs(1);
		printf("Case #%d: %lld\n", test, soln.getsol());
	}
	return 0;
}
