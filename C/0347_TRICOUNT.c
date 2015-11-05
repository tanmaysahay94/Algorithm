#include <stdio.h>

int main()
{
	unsigned long long t, n, p;
	scanf("%lld", &t);
	while (t--)
	{
		scanf("%lld", &n);
		p = n >> 1;
		if (n & 1)
			printf("%lld\n", n * (n + 1) * (n + 2) / 6 + p * (p + 1) * (4 * p + 5) / 6);
		else
			printf("%lld\n", n * (n + 1) * (n + 2) / 6 + p * (p + 1) * (4 * p - 1) / 6);
	}
	return 0;
}
