#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n;
		scanf("%d", &n);
		vector<long long> f(n), in(n), r(n), vis(n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &f[i]);
			f[i]--;
			in[f[i]]++;
		}
		for (int i = 0; i < n; i++)
			scanf("%lld", &r[i]);
		queue<long long> leaf;
		for (int i = 0; i < n; i++)
			if (not in[i])
				leaf.push(i);
		// BFS DP starting at leaves
		while (not leaf.empty())
		{
			int i = leaf.front(); leaf.pop();
			r[f[i]] += max(0LL, r[i]);
			in[f[i]]--;
			if (not in[f[i]])
				leaf.push(f[i]);
		}
		// r[i] where i is in a cycle stores best possible value for i-th node
		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			if (not in[i] or vis[i])
				continue;
			long long node = i;
			long long tmp = 0;
			while (not vis[node])
			{
				vis[node] = true;
				tmp += r[node];
				node = f[node];
			}
			if (tmp > 0) ans += tmp;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
