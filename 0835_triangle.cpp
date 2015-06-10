#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef long long LL;

int main()
{
	optimizeIO();
	LL x, y;
	cin >> x >> y;
	LL x1, y1, x2, y2;
	if (x >= 0)
		if (y >= 0)
			x1 = 0, y1 = y + x, x2 = x + y, y2 = 0;
		else
			x1 = 0, y1 = y - x, x2 = x - y, y2 = 0;
	else
		if (y >= 0)
			x1 = x - y, y1 = 0, x2 = 0, y2 = y - x;
		else
			x1 = x + y, y1 = 0, x2 = 0, y2 = y + x;
	cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	return 0;
}
