#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;
const LL maxn = 1e6+ 5;

vector<LL> fact(maxn);

bool excellent(LL sum, LL a, LL b)
{
	while (sum)
	{
		LL dig = sum % 10;
		if (dig != a and dig != b)
			return false;
		sum /= 10;
	}
	return true;
}

LL powmod(LL a, LL b)
{
	a %= mod;
	LL ret = 1;
	while (b)
	{
		if (b & 1)
			ret = (ret * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ret;
}

void precalc()
{
	fact[0] = 1;
	for (int i = 1; i < (int) fact.size(); i++)
		fact[i] = (i * fact[i - 1]) % mod;
}

LL mul(LL n, LL i)
{
	LL ret = fact[n];
	LL den = (fact[i] * fact[n - i]) % mod;
	ret = (ret * powmod(den, mod - 2)) % mod;
	return ret;
}

int main()
{
	precalc();
	LL a, b, n, ans = 0;
	scanf("%lld%lld%lld", &a, &b, &n);
	for (LL i = 0; i <= n; i++)
	{
		LL sum = a * i + b * (n - i);
		if (excellent(sum, a, b))
		{
			ans += mul(n, i);
			ans %= mod;
		}
	}
	cout << ans;
	return 0;
}
