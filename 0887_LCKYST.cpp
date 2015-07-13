#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long n, val;

long long ans(long long);
long long cnt(long long);

int main()
{
	optimizeIO();
	cin >> n;
	while (n--)
	{
		cin >> val;
		cout << ans(val) << '\n';
	}
	return 0;
}

long long ans(long long val)
{
	while (cnt(val) < cnt(val << 2))
		val <<= 2;
	return val;
}

long long cnt(long long val)
{
	long long ret = 0;
	while (val % 10 == 0)
		ret++, val /= 10;
	return ret;
}
