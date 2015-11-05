#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

const LL maxn = 1e5 + 3;
const LL INF = LLONG_MAX;

typedef pair<LL, LL> pll;

LL N, M, S;
vector<pll> G[maxn];		// first - weight, second - destination, idx - source
vector<LL> special;
vector<LL> dist;
vector<bool> isset;
int setcount = 0;

struct cmp
{
	bool operator() (const pll& a, const pll& b)
	{
		return a.first > b.first;
	}
};

int main()
{
	scanf("%lld%lld", &N, &M);
	dist = vector<LL> (N + 1, INF);
	isset = vector<bool> (N + 1, false);
	LL u, v, w;
	for (int i = 0; i < M; i++)
	{
		scanf("%lld%lld%lld", &u, &v, &w);
		G[u].push_back(make_pair(w, v));
		G[v].push_back(make_pair(w, u));
	}
	scanf("%lld", &S);
	setcount += S;
	for (int i = 0; i < S; i++)
	{
		int splnode;
		scanf("%d", &splnode);
		special.push_back(splnode);
		dist[splnode] = 0;
		isset[splnode] = true;
	}
	priority_queue<pll, vector<pll>, cmp> pq;	// first - weight, second - destination
	for (int i = 0; i < S; i++)
		for (int j = 0; j < (int) G[special[i]].size(); j++)
		{
			LL source = special[i];
			LL destination = G[source][j].second;
			LL weight = G[source][j].first;
			pq.push(make_pair(weight, destination));
		}
	while (!pq.empty())
	{
		pll rem = pq.top(); pq.pop();
		LL wt = rem.first;
		LL loc = rem.second;
		dist[loc] = min(dist[loc], wt);
		isset[loc] = true;
		setcount++;
		for (int i = 0; i < (int) G[loc].size(); i++)
			if (!isset[G[loc][i].second])
				pq.push(make_pair(G[loc][i].first + wt, G[loc][i].second));
	}
	for (int i = 1; i <= N; i++)
		printf("%lld\n", dist[i]);
	return 0;
}
