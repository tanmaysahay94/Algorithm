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
	long long t, n;
	cin >> t;
	while (t--)
	{
		long long ans = 0;
		cin >> n;
		for (long long i = 1; i * i <= n; i++)
		{
			if (n % i)
				continue;
			long long j = n/i;
			ans += i;
			if (i != j)
				ans += j;
		}
		cout << ans << endl;
	}
	return 0;
}
