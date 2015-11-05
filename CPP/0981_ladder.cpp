#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> v(n), f(n), g(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	f[n - 1] = n - 1;
	for (int i = n - 2; i >= 0; i--)
		if (v[i] <= v[i + 1])
			f[i] = f[i + 1];
		else
			f[i] = i;
	g[0] = 0;
	for (int i = 1; i < n; i++)
		if (v[i] <= v[i - 1])
			g[i] = g[i - 1];
		else
			g[i] = i;
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (f[--l] >= g[--r])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
