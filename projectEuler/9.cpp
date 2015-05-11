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
	long long t;
	cin >> t;
	while (t--)
	{
		long long n;
		cin >> n;
		long long ans = -1;
		for (long long a = 1; a <= (n-1)/3+1; a++)
			for (long long b = a + 1; b <= a + (n-1)/3+1; b++)
			{
				long long c = n - a - b;
				if (not (a < b and b < c))
					continue;
				if (c * c == a * a + b * b)
					ans = max(ans, a * b * c);
			}
		cout << ans << endl;
	}
	return 0;
}
