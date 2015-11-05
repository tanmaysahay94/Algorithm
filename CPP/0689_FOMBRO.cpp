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
 
vector<long long> fwd(1e6 + 5), bwd(1e6 + 5), mid(1e6 + 5);

int main()
{
	optimizeIO();
	long long t, n, m, q, r;
	cin >> t;
	while (t--)
	{
		cin >> n >> m >> q;
		fwd[0] = fwd[1] = 1;
		for (long long i = 2; i <= n; i++)
			fwd[i] = (fwd[i - 1] * powMod(i, i - 1, m)) % m;
		bwd[n] = n;
		for (long long i = n - 1, j = 2; i >= 1; i--, j++)
			bwd[i] = (bwd[i + 1] * powMod(i, j, m)) % m;
		long long middle = n/2 + 1;
		if (n & 1)
			mid[middle] = middle % m;
		else
			mid[middle] = 1 % m;
		for (long long i = middle - 1; i >= 1; i--)
			mid[i] = ((mid[i + 1] * i) % m * (n - i + 1) % m) % m;
		while (q--)
		{
			cin >> r;
			r = min(r, n - r);
			long long ans = powMod(mid[r + 1], r, m);
			ans = (ans * fwd[r]) % m;
			ans = (ans * bwd[n - r + 1]) % m;
			cout << ans << endl;
		}
	}
	return 0;
}
