#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

vector<LL> a, b, g;
int n, m;

LL f(int idx)
{
	LL ret = 0;
	for (int i = 0; i < n; i++)
		ret += abs(a[i] - (b[i] + g[idx]));
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		a.resize(n), b.resize(n);
		for (int i = 0; i < n; i++)
			scanf("%lld", &a[i]);
		for (int i = 0; i < n; i++)
			scanf("%lld", &b[i]);
		scanf("%d", &m);
		g.resize(m);
		for (int i = 0; i < m; i++)
			scanf("%lld", &g[i]);
		sort(g.begin(), g.end());
		int l = 0, r = m - 1;
		while (r - l > 3)
		{
			int p = l + (r - l) / 3;
			int q = r - (r - l) / 3;
			LL a = f(p), b = f(q);
			if (a > b) l = p;
			else r = q;
		}
		LL ans = 1e15, val = 1e15;
		for (int i = l; i <= r; i++)
		{
			LL a = f(i);
			if (a < ans)
				ans = a, val = g[i];
			else if (a == ans and g[i] < val)
				val = g[i];
		}
		printf("%lld\n", val);
	}
	return 0;
}
