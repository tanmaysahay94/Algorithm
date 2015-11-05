#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

const LL mod = 1e9 + 7;
const LL maxn = 2*(1e6+ 7);

LL fac[maxn], inv[maxn];

LL modpow(LL a, LL b)
{
	if (a == 0)
		return 0;
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

LL choose(LL n, LL r)
{
	LL ret = fac[n];
	ret = (ret * inv[r]) % mod;
	ret = (ret * inv[n - r]) % mod;
	return ret;
}

void preprocess()
{
	fac[0] = 1, inv[0] = 1, fac[1] = 1, inv[1] = 1;
	for (int i = 2; i < maxn; i++)
	{
		fac[i] = (i * fac[i - 1]) % mod;
		inv[i] = modpow(fac[i], mod - 2);
	}
}

int main()
{
	preprocess();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		LL m, n;
		scanf("%lld%lld", &m, &n);
		printf("%lld\n", choose(n + m - 2, n - 1));
	}
	return 0;
}
