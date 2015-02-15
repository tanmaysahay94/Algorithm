#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long powMod(long long base, long long pow, long long mod)
{
	base %= mod;
	long long ret = 1;
	while (pow)
	{
		if (pow & 1)
			ret = (ret * base) % mod;
		base = (base * base) % mod;
		pow >>= 1;
	}
	return ret;
}

vector<long long> fwd(1e6 + 5), bwd(1e6 + 5);

int main()
{
	optimizeIO();
	long long t, n, m, q, r;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> q;
		fwd[0] = 1;
		for (long long i = 1; i <= n; i++)
			fwd[i] = (fwd[i - 1] * powMod(i, i - 1, m)) % m;
		bwd[n] = n;
		for (long long i = n - 1, j = 2; i >= 1; i--, j++)
			bwd[i] = (bwd[i + 1] * powMod(i, j, m)) % m;
		while (q--)
		{
			cin >> r;
			long long low = min(r, n - r);
			long long high = max(r, n - r);
			long long ans = (fwd[low] * bwd[high + 1]) % m;
			for (long long i = low + 1; i <= high; i++)
				ans = (ans * powMod(i, low, m)) % m;
			cout << ans << endl;
		}
	}
	return 0;
}
