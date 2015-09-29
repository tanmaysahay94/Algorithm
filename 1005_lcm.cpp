#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f(LL i, LL j, LL k)
{
	i = (i * j) / __gcd(i, j);
	return (i * k) / __gcd(i, k);
}

int main()
{
	LL n;
	cin >> n;
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	if (n == 2)
	{
		cout << 2;
		return 0;
	}
	LL ans = -1;
	for (int i = max(1LL, n - 50); i <= n; i++)
		for (int j = max(1LL, n - 50); j <= n; j++)
			for (int k = max(1LL, n - 50); k <= n; k++)
				ans = max(ans, f(i, j, k));
	cout << ans;
	return 0;
}
