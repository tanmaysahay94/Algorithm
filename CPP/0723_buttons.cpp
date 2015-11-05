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
	long long n, m;
	cin >> n >> m;
	int ans = 0;
	while (m > n)
	{
		if (m & 1)
			m++, ans++;
		m >>= 1, ans++;
	}
	cout << n - m + ans << endl;
	return 0;
}
