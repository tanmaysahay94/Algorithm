#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

LL powmod(LL a, LL b)
{
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

int main()
{
	LL n;
	cin >> n;
	LL a = powmod(27, n);
	LL b = powmod(7, n);
	a -= b;
	a %= mod;
	while (a < 0)
		a += mod;
	cout << a;
	return 0;
}
