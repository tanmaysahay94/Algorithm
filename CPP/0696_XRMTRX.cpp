#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long mod = 1e9 + 7;
typedef pair<long long, long long> pll;

pll solve(long long l, long long r)
{
	long long mid;
	if (l == r)
		return pll(0, 1);
	for (mid = 1; mid <= r; mid <<= 1);
	mid >>= 1;
	if (l == 0)
	{
		long long val = (mid << 1) - 1;
		int res = 2LL * (mid % mod) * ((r - mid + 1) % mod) % mod;
		if (r < val)
			return pll(val, res);
		return pll(val, (res << 1) % mod);
	}
	if (r == (mid << 1) - 1)
		return solve(0, r - l);
	pll p1, p2;
	if (l < mid)
	{
		p1 = solve(0, r - mid);
		p2 = solve(0, mid - 1 - l);
		if (p1.first < p2.first)
			swap(p1, p2);
		if (p1.first == p2.first)
			return pll(p1.first, (p1.second + p2.second) % mod);
		return p1;
	}
	return solve(l - mid, r - mid);
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		long long l, r;
		cin >> l >> r;
		pll ans = solve(l, r);
		cout << ans.first << ' ' << ans.second << endl;
	}
	return 0;
}
