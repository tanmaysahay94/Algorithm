#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int R[20];

void solve()
{
	int n, m, k;
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", R + i);
	int lim = 1 << n;
	int ans = 31;
	for (int mask = 0; mask < lim; mask++)
	{
		bool arrest = false;
		for (int start = 0; start <= n - k and not arrest; start++)
		{
			int mx = -1;
			for (int i = start; i < start + k; i++)
				mx = max(mx, R[i] + ((mask >> i) & 1));
			int cnt = 0;
			for (int i = start; i < start + k and not arrest; i++)
			{
				if (mx == R[i] + ((mask >> i) & 1))
					cnt++;
				if (cnt >= m)
					arrest = true;
			}
		}
		if (not arrest)
			ans = min(ans, __builtin_popcount(mask));
	}
	if (ans == 31)
		printf("-1\n");
	else
		printf("%d\n", ans);
}

int main()
{
	optimizeIO();
	int t;
	scanf("%d", &t);
	while (t--)
		solve();
	return 0;
}
