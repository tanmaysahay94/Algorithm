#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long g(long long n)
{
	return (n * (n + 1)) / 2;
}

long long f(long long n)
{
	long long a = (n * (n + 1) * (2 * n + 1)) / 6;
	long long b = g(n);
	long long c = b * b;
	return abs(a - c);
}

int main()
{
	optimizeIO();
	long long t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout << f(n) << endl;
	}
	return 0;
}
