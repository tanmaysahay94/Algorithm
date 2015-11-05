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
	int n, m;
	cin >> n >> m;
	int ulim = (n * (n + 1)) / 2;
	if (m > ulim)
	{
		cout << -1;
		return 0;
	}
	int ans = 1;
	int tmp = n;
	int foo = n - 1;
	while (tmp < m and foo)
	{
		tmp += foo;
		foo--;
		ans++;
	}
	cout << ans;
	return 0;
}
