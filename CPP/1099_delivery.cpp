#include <bits/stdc++.h>
using namespace std;

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename __Tp1>
void __f(const char* name, __Tp1&& __tp1){
	cerr << name << " : " << __tp1 << std::endl;
}
template <typename __Tp1, typename... __Tps>
void __f(const char* names, __Tp1&& __tp1, __Tps&&... __tps){
	const char* comma = strchr(names + 1, ',');
	cerr.write(names, comma - names) << " : " <<  __tp1 << " | " ;
	__f(comma+1, __tps...);
}
#else
#define trace(...)
#endif

const int maxn = 1e5 + 5;

class solution
{
	public:
		int n, m, k;
		bool toVisit[maxn];
		int color[maxn];

		vector<int> G[maxn], GR[maxn];
		vector<unordered_set<int> > GN;
		stack<int> S;
		int visited[maxn];
		vector<vector<int> > componenents;
		vector<int> inDegree;
		unordered_set<int> componenentsConsidered;
		vector<int> topoOrdering;

		void init()
		{
			for (int i = 1; i <= n; i++)
				G[i].clear(), GR[i].clear();
			for (auto &gn: GN)
				gn.clear();
			while (S.size())
				S.pop();
			memset(visited, 0, sizeof(visited));
			for (auto &c: componenents)
				c.clear();
			inDegree.clear();
			componenentsConsidered.clear();
			topoOrdering.clear();
			memset(toVisit, 0, sizeof(toVisit));
			for (int i = 0; i < maxn; i++)
				color[i] = -1;
		}

		void dfs1(int u)
		{
			if (visited[u])
				return;
			visited[u] = 1;
			for (auto v: G[u])
				dfs1(v);
			S.push(u);
		}

		void dfs2(int u, int c, vector<int>& comp)
		{
			if (visited[u])
				return;
			visited[u] = 1;
			color[u] = c;
			if (toVisit[u])
				comp.push_back(u);
			for (auto v: GR[u])
				dfs2(v, c, comp);
		}

		void main()
		{
			scanf("%d%d%d", &n, &m, &k);
			init();
			for (int i = 0; i < k; i++)
			{
				int city;
				scanf("%d", &city);
				toVisit[city] = 1;
			}
			for (int i = 0; i < m; i++)
			{
				int x, y;
				scanf("%d%d", &x, &y);
				G[x].push_back(y);
				GR[y].push_back(x);
			}
			for (int i = 1; i <= n; i++)
				if (not visited[i])
					dfs1(i);
			memset(visited, 0, sizeof(visited));
			int c = 0;
			vector<int> comp;
			while (not S.empty())
			{
				int u = S.top();
				S.pop();
				if (visited[u])
					continue;
				comp = vector<int> ();
				dfs2(u, c++, comp);
				componenents.push_back(comp);
			}
			for (auto &C: componenents)
				sort(C.begin(), C.end());
			GN = vector<unordered_set<int> > (c);
			for (int i = 1; i <= n; i++)
				for (auto j: G[i])
					if (not GN[color[i]].count(color[j]) and color[i] != color[j])
						GN[color[i]].insert(color[j]);
			vector<int> dp(c, 0);
			vector<int> to(c, -1);
			for (int i = c - 1; i >= 0; i--)
			{
				dp[i] = componenents[i].size();
				for (auto j: GN[i])
				{
					int foo = componenents[i].size() + dp[j];
					if (foo > dp[i])
					{
						dp[i] = foo;
						to[i] = j;
					}
				}
			}
			int startPoint = -1;
			for (int i = 0; i < c; i++)
				if (dp[i] == k)
					startPoint = i;
			if (startPoint == -1)
				printf("-1");
			else
			{
				while (startPoint != -1)
				{
					for (auto u: componenents[startPoint])
						printf("%d ", u);
					startPoint = to[startPoint];
				}
			}
			printf("\n");
		}
};

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		solution s;
		s.main();
	}
	return 0;
}
