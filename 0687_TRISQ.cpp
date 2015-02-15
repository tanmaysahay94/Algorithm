#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long sum(long long n)
{
	return ((n * (n + 1))/2);
}

int main()
{
	optimizeIO();
	long long t, b;
	cin >> t;
	while (t--)
	{
		cin >> b;
		cout << sum(b/2 - 1) << endl;
	}
	return 0;
}
