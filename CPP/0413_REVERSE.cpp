#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <bits/stdc++.h>
#include <stack>
#include <cstdlib>
#include <set>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

struct cmp
{
	bool operator() (const pair<int, int> &a, const pair<int, int> &b)
	{
		return a.first > b.first;
	}
};

LL dijkstra(vector<pair<LL, LL> > graph[], LL n)
{
	LL dest = n - 1;
	LL inf = 1e10;
	vector<LL> distance(n, inf);
	vector<bool> locked(n, false);
	priority_queue<pair<LL, LL>, vector<pair<LL, LL> >, cmp> pq;
	pq.push(mp(0, 0));
	while (not locked[dest] and not pq.empty())
	{
		pair<LL, LL> justRem = pq.top();
		pq.pop();
		LL loc = justRem.s;
		LL dis = justRem.f;
		distance[loc] = min(distance[loc], dis);
		locked[loc] = true;
		for (int i = 0; i < graph[loc].size(); i++)
			if (not locked[graph[loc][i].s])
				pq.push(mp(dis + graph[loc][i].f, graph[loc][i].s));
	}
	if (locked[dest])
		return distance[dest];
	return -1;
}

int main()
{
	LL n, m, i, a, b;
	SLL(n); SLL(m);
	vector<pair<LL, LL> > graph[n];
	for (i = 0; i < m; i++)
	{
		SLL(a); SLL(b);
		a--; b--;
		if (a != b)
		{
			graph[a].pb(mp(0, b));
			graph[b].pb(mp(1, a));
		}
		else
			graph[a].pb(mp(0, b));
	}
	for (i = 0; i < n; i++)
		sortv(graph[i]);
	printf("%lld\n", dijkstra(graph, n));
	return 0;
}
