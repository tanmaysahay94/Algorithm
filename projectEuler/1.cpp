#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

long long f(long long n)
{
	return (n * (n + 1))/2;
}

int main()
{
	optimizeIO();
	int t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		n--;
		long long ans = 3 * f(n/3);
		ans += 5 * f(n/5);
		ans -= 15 * f(n/15);
		cout << ans << endl;
	}
	return 0;
}
