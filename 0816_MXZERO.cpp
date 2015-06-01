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
	int t, n, v;
	cin >> t;
	while (t--)
	{
		int cnt = 0;
		cin >> n;
		while (n--)
		{
			cin >> v;
			cnt += v;
		}
		cout << cnt << "\n";
	}
	return 0;
}
