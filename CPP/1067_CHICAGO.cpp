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

const int maxn = 1e2 + 5;
vector<pair<double, int> > eds[maxn];

int main()
{
	int n, m;
	scanf("%d", &n);
	while (n)
	{
		scanf("%d", &m);
		for (int i = 0; i < m; i++)
		{
			int a, b;
			double p;
			scanf("%d%d%lf", &a, &b, &p);
			a--, b--, p /= 100;
			eds[a].push_back(make_pair(p, b));
			eds[b].push_back(make_pair(p, a));
		}
		vector<bool> vis(n);
		priority_queue<pair<double, int> > pq;
		pq.push(make_pair(100, 0));
		double ans;
		while (pq.size())
		{
			pair<double, int> best = pq.top(); pq.pop();
			double prob = best.first;
			int loc = best.second;
			if (vis[loc]) continue;
			vis[loc] = 1;
			if (loc == n - 1)
			{
				ans = prob;
				break;
			}
			for (auto &u: eds[loc])
				pq.push(make_pair(u.first * prob, u.second));
		}
		printf("%.6lf percent\n", ans);
		for (auto &ed: eds)
			ed.clear();
		scanf("%d", &n);
	}
	/*
	   int __T;
	   scanf("%d", &__T);
	   for (int t = 1; t <= __T; t++)
	   {
	   }
	   */
	return 0;
}
