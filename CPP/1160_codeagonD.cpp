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

typedef long long LL;

const int maxn = 3005;
const int maxr = 505;
const LL inf = maxn * maxr;
LL n, m, S[2];

vector<pair<pair<int, int>, int> > eds;
unordered_map<LL, LL> G[maxn];
vector<LL> ansS(maxn), ansD(maxn);

void dijkstra1(int vertex)
{
	vector<LL>& tmp = ansD;
	tmp[vertex] = 0;
	set<pair<LL, LL> > pq;
	pq.insert(make_pair(tmp[vertex], vertex));
	while (pq.size())
	{
		pair<LL, LL> best = *pq.begin(); pq.erase(pq.begin());
		LL dist = best.first;
		LL loc = best.second;
		tmp[loc] = min(tmp[loc], dist);
		for (auto u: G[loc])
			if (u.second + dist < tmp[u.first])
			{
				pq.erase(make_pair(tmp[u.first], u.first));
				tmp[u.first] = u.second + dist;
				pq.insert(make_pair(tmp[u.first], u.first));
			}
	}
}

void dijkstra2(int vertex)
{
	vector<LL>& tmp = ansS;
	tmp[vertex] = 0;
	set<pair<LL, LL> > pq;
	pq.insert(make_pair(tmp[vertex], vertex));
	while (pq.size())
	{
		pair<LL, LL> best = *pq.begin(); pq.erase(pq.begin());
		LL dist = best.first;
		LL loc = best.second;
		tmp[loc] = min(tmp[loc], dist);
		for (auto u: G[loc])
			if (u.second + dist < tmp[u.first])
			{
				pq.erase(make_pair(tmp[u.first], u.first));
				tmp[u.first] = u.second + dist;
				pq.insert(make_pair(tmp[u.first], u.first));
			}
	}
}

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		scanf("%lld%lld", &n, &m);
		for (int i = 0; i < n; i++)
		{
			G[i].clear();
			ansS[i] = ansD[i] = inf;
		}
		eds.clear();
		for (int i = 0; i < m; i++)
		{
			LL x, y, r, t;
			scanf("%lld%lld%lld%lld", &x, &y, &r, &t);
			x--, y--;
			if (G[x].count(y)) G[x][y] = min(G[x][y], r); else G[x][y] = r;
			if (G[y].count(x)) G[y][x] = min(G[y][x], r); else G[y][x] = r;
			eds.push_back(make_pair(make_pair(x, y), t));
		}
		scanf("%lld%lld", &S[0], &S[1]);
		for (int i = 0; i < 2; i++) S[i]--;
		dijkstra1(S[1]);
		dijkstra2(S[0]);
		if (ansS[S[1]] == inf or ansD[S[0]] == inf)
		{
			printf("-1\n");
			continue;
		}
		LL ans = min(ansS[S[1]], ansD[S[0]]);
		for (auto &ed: eds)
		{
			int x = ed.first.first;
			int y = ed.first.second;
			LL t = ed.second;
			if (ansS[x] != inf and ansD[y] != inf) ans = min(ans, ansS[x] + t + ansD[y]);
			if (ansS[y] != inf and ansD[x] != inf) ans = min(ans, ansS[y] + t + ansD[x]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
