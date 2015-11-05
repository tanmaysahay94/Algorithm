#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long t;
	cin >> t;
	while (t--)
	{
		long long i = 0, n, s, sum;
		cin >> n >> s;
		if (s == (n * (n + 1)) >> 1)
		{
			cout << 0 << endl;
			continue;
		}
		sum = n - 1;
		while (sum < s)
		{
			i++;
			sum += i;
		}
		cout << n - i << endl;
	}
	return 0;
}
