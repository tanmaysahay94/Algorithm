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
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

void dfs(vector<VI>& graph, int node, int depth, VI& num)
{
	if (depth == 2)
	{
		num[node]++;
		return;
	}
	for (int i = 0; i < (int) graph[node].size(); i++)
		dfs(graph, graph[node][i], depth + 1, num);
}

int main()
{
	int n, m, a, b;
	cin >> n >> m;
	vector<VI> graph(n);
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		graph[a-1].pb(b-1);
	}
	LL ans = 0;
	VI num(n, 0);
	for (int i = 0; i < n; i++)
	{
		num = VI (n, 0);
		dfs(graph, i, 0, num);
		for (int j = 0; j < n; j++)
			if (i != j)
				ans += (num[j] * (num[j] - 1))/2;
	}
	cout << ans << endl;
	return 0;
}
