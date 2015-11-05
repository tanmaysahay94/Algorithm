#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

struct edge
{
	int beg, dest, is_track;
	LL wt;
	edge(int a, int b, LL c, int d)
	{
		beg = a;
		dest = b;
		wt = c;
		is_track = d;
	}
	bool operator <(const edge& foo) const
	{
		if (wt < foo.wt)
			return true;
		if (wt == foo.wt)
			if (is_track < foo.is_track)
				return true;
		return false;
	}
};

struct hnode
{
	int loc, prevEdge, edgeType;
	LL dist;
	hnode(int a, LL b, int c, int d)
	{
		loc = a;
		dist = b;
		prevEdge = c;
		edgeType = d;
	}
	bool operator <(const hnode& foo) const
	{

		if (dist > foo.dist)
			return true;
		if (dist == foo.dist)
			if (edgeType > foo.edgeType)
				return true;
		return false;
	}
};

LL n, m, k;

vector<int> G[100100];
vector<LL> D(100100);
vector<int> vis(100100);
vector<edge> V;
vector<int> last(100100);
set<int> toCheck;
vector<int> inDeg(100100);

int main()
{
	optimizeIO();
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		D[i] = 1e18;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		LL x;
		cin >> u >> v >> x;
		V.push_back(edge(u, v, x, 0));
		G[u].push_back(cnt);
		G[v].push_back(cnt);
		cnt++;
	}
	for (int i = 0; i < k; i++)
	{
		LL x; int v;
		cin >> v >> x;
		toCheck.insert(v);
		inDeg[v]++;
		V.push_back(edge(1, v, x, 1));
		G[1].push_back(cnt);
		G[v].push_back(cnt);
		cnt++;
	}
	priority_queue<hnode, vector<hnode> > pq;
	pq.push(hnode(1, 0, -1, -1));
	while (!pq.empty())
	{
		hnode rem = pq.top(); pq.pop();
		if (rem.dist < D[rem.loc]) last[rem.loc] = rem.edgeType, D[rem.loc] = rem.dist;
		if (vis[rem.loc])continue;
		vis[rem.loc] = 1;
		for (int i = 0; i < (int) G[rem.loc].size(); i++)
		{
			int idx = G[rem.loc][i];
			edge e = V[idx];
			int next, source, prev; LL length;
			if (rem.loc == e.beg) next = e.dest;
			else next = e.beg;
			source = idx;
			if (vis[next]) continue;
			length = e.wt + D[rem.loc];
			prev = V[idx].is_track;
			pq.push(hnode(next, length, source, prev));
		}
	}
	int ans = 0;
	set<int>::iterator it;
	for (it = toCheck.begin(); it != toCheck.end(); it++)
	{
		LL nd = *it;
		if (last[nd] == 0)
			ans++;
		else if (last[nd] == 1)
			ans += inDeg[nd] - 1;
	}
	cout << ans << endl;
	return 0;
}
