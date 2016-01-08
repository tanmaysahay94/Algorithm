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

const int maxn = 3005;
const int maxr = 355;
const int infi = maxn * maxr; 

unordered_map<int, int> G[maxn];
int ans[maxn];

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) G[i].clear(), ans[i] = infi;
		for (int i = 0; i < m; i++)
		{
			int x, y, r;
			scanf("%d%d%d", &x, &y, &r);
			x--, y--;
			if (G[x].count(y)) G[x][y] = min(G[x][y], r); else G[x][y] = r;
			if (G[y].count(x)) G[y][x] = min(G[y][x], r); else G[y][x] = r;
		}
		int S;
		scanf("%d", &S);
		S--;
		ans[S] = 0;
		set<pair<int, int> > pq;
		pq.insert(make_pair(ans[S], S));
		while (pq.size())
		{
			pair<int, int> best = *pq.begin(); pq.erase(pq.begin());
			int dist = best.first;
			int loc = best.second;
			ans[loc] = min(ans[loc], dist);
			for (auto u: G[loc])
				if (u.second + dist < ans[u.first])
				{
					pq.erase(make_pair(ans[u.first], u.first));
					ans[u.first] = u.second + dist;
					pq.insert(make_pair(ans[u.first], u.first));
				}
		}
		for (int i = 0; i < n; i++)
			if (i != S)
				printf("%d ", ans[i] == infi ? -1 : ans[i]);
		printf("\n");
	}
	return 0;
}
