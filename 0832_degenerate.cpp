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
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a * d < b * c)
		swap(a, b), swap(c, d);
	double l = 0, r = INT_MAX;
	for (int i = 0; i < 2222222; i++)
	{
		double diff = (l + r) / 2;
		double foo = (a - diff) * (d - diff);
		foo = min(foo, (a - diff) * (d + diff));
		foo = min(foo, (a + diff) * (d - diff));
		foo = min(foo, (a + diff) * (d + diff));
		double bar = (b - diff) * (c - diff);
		bar = max(bar, (b - diff) * (c + diff));
		bar = max(bar, (b + diff) * (c - diff));
		bar = max(bar, (b + diff) * (c + diff));
		if (foo > bar)
			l = diff;
		else
			r = diff;
	}
	printf("%.9lf\n", l);
	return 0;
}
