#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

bool f(long long a, long long b)
{
	if (b == 1)
		return true;
	if (a == 1)
		return false;
	long long c = __gcd(a, b);
	return f(c, b/c);
}

int main()
{
	optimizeIO();
	long long t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (f(a, b))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
