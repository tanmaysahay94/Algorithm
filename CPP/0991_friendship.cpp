#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int n;
	LL d;
	scanf("%d%lld", &n, &d);
	vector<pair<LL, LL> > v(n);
	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &v[i].first, &v[i].second);
	sort(v.rbegin(), v.rend());
	vector<int> possible(n);
	int ptr = 0;
	for (int i = 0; i < n; i++)
	{
		while (ptr < n and v[i].first - v[ptr].first < d)
			ptr++;
		if (ptr == n)
		{
			ptr--;
			possible[i] = ptr;
			continue;
		}
		ptr--;
		possible[i] = ptr;
		ptr++;
	}
	vector<long long> fn(n + 1);
	for (int i = 0; i < n; i++)
		fn[i + 1] = v[i].second;
	for (int i = 1; i <= n; i++)
		fn[i] += fn[i - 1];
	LL ans = -1;
	for (int i = 0; i < n; i++)
	{
		int curr = i;
		int lim = possible[i];
		curr++, lim++;
		ans = max(ans, fn[lim] - fn[curr - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}
