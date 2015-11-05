#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	double sum = n;
	double ans = INT_MAX;
	int cnt = 0;
	for (int i = 0; i < 2 * n; i++)
	{
		double val;
		cin >> val;
		val = val - (int) val;
		if (not val)
			cnt++;
		sum -= val;
	}
	for (int i = 0; i <= min(n, cnt); i++)
		ans = min(ans, abs(sum - i));
	printf("%.3lf\n", abs(ans));
	return 0;
}
