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
	if (n == 1)
	{
		cout << 1;
		return 0;
	}
	if (m <= n / 2) cout << m + 1;
	else cout << m - 1;
	return 0;
}
