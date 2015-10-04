#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 6;

vector<int> G[maxn];
vector<int> a(maxn), c(maxn);
int n;

set<int> solve(int node)
{
	set<int> ret;
	ret.insert(c[node]);
	if (G[node].empty())
	{
		a[node] = 1;
		return ret;
	}
	for (auto next: G[node])
	{
		set<int> tmp = solve(next);
		for (auto bar: tmp)
			ret.insert(bar);
	}
	a[node] = ((int) ret.size());
	return ret;
}

int main()
{
	scanf("%d", &n);
	int root;
	for (int i = 1; i <= n; i++)
	{
		int pi, ci;
		scanf("%d%d", &pi, &ci);
		if (not pi)
			root = i;
		c[i] = ci;
		G[pi].push_back(i);
	}
	set<int> S = solve(root);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}
