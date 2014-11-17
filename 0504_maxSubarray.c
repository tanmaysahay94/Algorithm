#include <stdio.h>

long long max(long long a, long long b)
{
	return a > b ? a : b;
}

int main()
{
	long long a[100010], i, n, val, cur = 0, ans = 0;
	scanf("%lld", &n);
	for (i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	cur = ans = max(a[0], 0);
	for (i = 1; i < n; i++)
	{
		cur = max(a[i], cur + a[i]);
		ans = max(ans, cur);
	}
	printf("%lld\n", ans);
	return 0;
}
