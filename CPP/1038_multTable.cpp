#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

LL f(LL n, LL m, LL mid)
{
	LL ret = 0;
	for (LL i = 1; i <= n; i++)
		ret += min(m, mid / i - (mid % i == 0));
	return ret;
}

int main()
{
	LL n, m, k;
	cin >> n >> m >> k;
	LL s = 1, e = n * m;
	while (s <= e)
	{
		LL mid = (s + e) / 2;
		LL val = f(n, m, mid);
		if (val < k)
			s = mid + 1;
		else
			e = mid - 1;
	}
	cout << e;
	return 0;
}
