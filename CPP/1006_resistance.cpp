#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b;
	cin >> a >> b;
	long long ans = 0;
	while (a > 0 and b > 0)
	{
		if (a >= b)
		{
			ans += a / b;
			a %= b;
		}
		else
		{
			ans += b / a;
			b %= a;
		}
	}
	cout << ans;
	return 0;
}
