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

const int maxn = 2e5 + 5;
const int inf = maxn;

unordered_set<int> G[maxn];
vector<int> ans(maxn);

int main()
{
	int __T;
	scanf("%d", &__T);
	for (int t = 1; t <= __T; t++)
	{
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			G[i].clear(), ans[i] = inf;
		for (int i = 0; i < M; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			x--, y--;
			G[x].insert(y);
			G[y].insert(x);
		}
		int S, cnt = N - 1;
		unordered_set<int> left;
		for (int i = 0; i < N; i++)
			left.insert(i);
		scanf("%d", &S);
		S--;
		left.erase(S);
		ans[S] = 0;
		queue<pair<int, int> > Q;
		Q.push(make_pair(S, 0));
		while (Q.size() and cnt)
		{
			pair<int, int> rem = Q.front(); Q.pop();
			int u = rem.first, dist = rem.second;
			unordered_set<int> tmp;
			for (auto v: left)
			{
				if (G[u].count(v)) continue;
				ans[v] = dist + 1;
				Q.push(make_pair(v, ans[v]));
				tmp.insert(v);
				cnt--;
			}
			for (auto v: tmp)
				left.erase(v);
		}
		for (int i = 0; i < N; i++)
			if (i != S)
				printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}
