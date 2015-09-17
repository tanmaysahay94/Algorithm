#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b;
	scanf("%lld%lld", &a, &b);
	if (b > a)
	{
		printf("-1\n");
		return 0;
	}
	int k = (a - b) / (2 * b);
	double x1, x2;
	if (k == 0)
		x1 = a;
	else
		x1 = (double) (a - b) / 2 / k;
	x2 = (double) (a + b) / 2 / (k + 1);
	printf("%.12lf\n", min(x1, x2));
	return 0;
}
