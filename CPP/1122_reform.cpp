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
int n, m;
int vis[maxn];
vector<int> G[maxn];

int hasCycle(int v, int lvl = 1)
{
	if (vis[v]) return (lvl - vis[v] > 2);
	vis[v] = lvl;
	int ret = 0;
	for (auto u: G[v]) ret |= hasCycle(u, lvl + 1);
	return ret;
}

int main()
{
	memset(vis, 0, sizeof(vis));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (not vis[i])
			if (not hasCycle(i))
				ans++;
	printf("%d\n", ans);
	return 0;
}
