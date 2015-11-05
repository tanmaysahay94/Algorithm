#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

int main()
{
	optimizeIO();
	long long n, val, ans = 0;
	cin >> n;
	vector<long long> pre(n + 1);
	for (long long i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] ^ i;
		cin >> val;
		ans ^= val;
		long long q = n/i;
		long long r = n%i;
		if (q & 1)
			ans ^= pre[i - 1];
		ans ^= pre[r];
	}
	cout << ans << endl;
	return 0;
}
