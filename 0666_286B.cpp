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

int mat[102][102][102];
vector<int> graph[102];
int n;

int bfs(int start, int end, VI& vis, int color)
{
	vis[start] = 1;
	if (start == end)
		return 1;
	for (int i = 0; i < (int) graph[start].size(); i++)
	{
		int next = graph[start][i];
		if (mat[start][next][color] and not vis[next] and bfs(next, end, vis, color))
			return 1;
	}
	return 0;
}

int main()
{
	int m, a, b, c;
	si(n); si(m);
	for (int i = 0; i < m; i++)
	{
		si(a); si(b); si(c);
		mat[a][b][c] = 1;
		mat[b][a][c] = 1;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	int q;
	si(q);
	while (q--)
	{
		si(a); si(b);
		VI vis(n+1, 0);
		int cnt = 0;
		for (int i = 1; i <= m; i++)
		{
			vis = VI(n+1, 0);
			if (bfs(a, b, vis, i))
				cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
}
