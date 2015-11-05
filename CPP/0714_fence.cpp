#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long a[5555];
long long n;

long long solve(long long l, long long r, long long b)
{
	if (l > r)
		return 0;
	long long val = 1e12, idx = 0;
	for (long long i = l; i <= r; i++)
		if (a[i] < val)
			val = a[i], idx = i;
	return min(solve(l, idx - 1, val) + solve(idx + 1, r, val) + (val - b), r - l + 1);
}

int main()
{
	optimizeIO();
	cin >> n;
	for (long long i = 0; i < n; i++)
		cin >> a[i];
	cout << solve(0, n - 1, 0) << endl;
	return 0;
}
