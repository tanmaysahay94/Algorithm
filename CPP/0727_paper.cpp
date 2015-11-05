#include <bits/stdc++.h>

using namespace std;

long long solve(long long a, long long b)
{
	if (b == 1) return a;
	return (a/b) + solve(b, a%b);
}

int main()
{
	long long a, b;
	cin >> a >> b;
	long long g = __gcd(a, b);
	cout << solve(a/g, b/g) << endl;
	return 0;
}
