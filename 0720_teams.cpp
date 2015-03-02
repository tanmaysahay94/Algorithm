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
	long long xp, nb;
	cin >> xp >> nb;
	long long n, m, ans = 0;
	for (long long i = 1; i <= xp; i++)
	{
		n = xp, m = nb;
		long long temp = 0;
		if (2 * i <= m)
			temp += i, m -= 2*i, n -= i;
		temp += min(m, n/2);
		ans = max(ans, temp);
	}
	cout << ans << endl;
	return 0;
}
