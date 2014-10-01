#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL n;
vector< vector<LL> > c;
vector<bool> visited;

LL dfs(LL start, LL end, LL cap)
{
	LL tot_cap = 0, maxcap;
	visited[start] = true;
	if(start==end || cap==0)
		tot_cap = cap;
	for(int i=0; i<n; i++)
		if(c[start][i] && !visited[i])
		{
			maxcap = dfs(i, end, min(cap, c[start][i]));
			if(maxcap)
			{
				c[start][i] -= maxcap;
				c[i][start] += maxcap;
				cap -= maxcap;
				tot_cap += maxcap;
			}
		}
	visited[start] = false;
	return tot_cap;
}

int main()
{
	LL m, start, end, capacity, tmp_cap;
	SLL(n); SLL(m);		//vertices and edges
	c.resize(n);
	visited.resize(n);
	for(int i=0; i<n; i++)
		c[i].resize(n);
	while (m--)		//Description of m edges
	{
		SLL(start); SLL(end); SLL(capacity);
		start--; end--;
		c[start][end] = capacity;
	}
	LL t;
	SLL(t);
	while (t--)
	{
		visited.resize(0);
		visited.resize(n);
		SLL(start); SLL(end);		//Source and sink
		start--; end--;
		tmp_cap = c[end][start];
		vector<vector<LL> > temp = c;
		c[end][start] = INT_MAX;
		LL tot_cap = dfs(start, end, INT_MAX);
		printf("%lld\n", tot_cap);
		c[end][start] = tmp_cap;
		c = temp;
	}
	return 0;
}
