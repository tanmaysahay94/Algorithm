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
	int t;
	cin >> t;
	while (t--)
	{
		int x, y, k, n, p, c, yes = 0;
		cin >> x >> y >> k >> n;
		x -= y;
		while (n--)
		{
			cin >> p >> c;
			if (c <= k and x <= p)
				yes = 1;
		}
		if (yes) cout << "LuckyChef\n";
		else cout << "UnluckyChef\n";
	}
	return 0;
}
