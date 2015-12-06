#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const LL mod = 1e9 + 7;

LL modPow(LL a, LL b, LL mod)
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
	LL p, k;
	cin >> p >> k;
	if (k == 0)
		cout << modPow(p, p - 1, mod);
	else if (k == 1)
		cout << modPow(p, p, mod);
	else
	{
		LL v = k, m = 1;
		while (v != 1) v = (v * k) % p, m++;
		cout << modPow(p, (p - 1) / m, mod);
	}
	return 0;
}
