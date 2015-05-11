#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

__int128_t lcm(__int128_t a, __int128_t b)
{
	return (a * b) / __gcd(a, b);
}

int main()
{
	optimizeIO();
	vector<__int128_t> ans(50);
	ans[1] = 1;
	for (__int128_t i = 2; i < 41; i++)
		ans[i] = lcm(ans[i - 1], i);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		cout << (long long) ans[n] << endl;;
	}
	return 0;
}
