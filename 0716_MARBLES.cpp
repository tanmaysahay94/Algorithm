#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long solve(long long a, long long b)
{
	long long n = a - 1;
	long long k = b - 1;
	if (k > n/2)
		k = n - k;
	long long ret = 1;
	for (long long i = 0; i < k; i++)
	{
		ret *= (n - i);
		ret /= (i + 1);
	}
	return ret;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		long long n, k;
		cin >> n >> k;
		cout << solve(n, k) << endl;
	}
	return 0;
}
