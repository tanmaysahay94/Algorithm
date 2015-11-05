#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[1000006];
	cin >> a[0] >> a[1];
	bool intersect = false;
	for (int i = 2; i < n; i++)
	{
		cin >> a[i];
		double vmax = max(a[i], a[i - 1]);
		double vmin = min(a[i], a[i - 1]);
		for (int j = 1; j < i - 1; j++)
		{
			double umax = max(a[j], a[j - 1]);
			double umin = min(a[j], a[j - 1]);
			if (umin < vmin and vmin < umax and umax < vmax)
				intersect = true;
			else if (vmin < umin and umin < vmax and vmax < umax)
				intersect = true;
		}
	}
	if (intersect) cout << "yes\n";
	else cout << "no\n";
	return 0;
}
