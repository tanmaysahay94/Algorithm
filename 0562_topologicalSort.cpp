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

int n;
vector<vector<pair<LL, LL> > > graph(10000);
vector<bool> visited(10000, false);
VI tOrd;

void dfs(int i)
{
	if (visited[i])
		return;
	visited[i] = true;
	vector<pair<LL, LL> >::iterator it;
	for (it = graph[i].begin(); it != graph[i].end(); it++)
		dfs(it -> f);
	tOrd.pb(i);
}

void tSort(int lim)
{
	for (int i = 0; i <= lim; i++)
		dfs(i);
}

int main()
{
	cin >> n;
	int start, end, lim = -1;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		start--; end--;
		graph[start].pb(mp(end, 1LL));
		lim = max(lim, max(start, end));
	}
	tSort(lim);
	for (int i = 0; i < tOrd.size(); i++)
		cout << tOrd[i] << " ";
	cout << endl;
	return 0;
}
