#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

const long long mod = 1e6 + 3;

long long countFact(long long n)
{
	long long k = 0;
	long long p = mod;
	while (n >= p)
	{
		k += n/p;
		n /= p;
	}
	return k;
}

long long pow(long long a, long long b)
{
	long long ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

long long InverseEuler(long long n)
{
	return pow(n, mod - 2);
}

long long factmod(long long n)
{
	long long ret = 1;
	while (n > 0)
	{
		for (long long i = 2, m = n % mod; i <= m; i++)
			ret = (ret * i) % mod;
		if ((n /= mod) % 2 > 0)
			ret = mod - ret;
	}
	return ret;
}

long long c(long long n, long long r)
{
	if (countFact(n) > countFact(r) + countFact(n - r))
		return 0;
	return (factmod(n) * ((InverseEuler(factmod(r)) * InverseEuler(factmod(n - r))) % mod)) % mod;
}

int main()
{
	optimizeIO();
	long long t;
	cin >> t;
	while (t--)
	{
		long long n, l, r;
		cin >> n >> l >> r;
		long long ans = c(r - l + n + 1, n);
		ans = (ans - 1) % mod;
		if (ans < 0) ans += mod;
		cout << ans << endl;
	}
	return 0;
}
