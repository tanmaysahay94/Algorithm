#include <stdio.h>

int main()
{
	long long n, i, ans = 0, curr = 0;
	scanf("%lld", &n);
	long long a[100005];
	for (i = 0; i < n; i++)
		scanf("%lld", a + i);
	for (i = 0; i < n; i++)
	{
		if (a[i] != 0)
			curr++;
		else
		{
			ans = ans > curr ? ans : curr;
			curr = 0;
		}
	}
	printf("%lld\n", ans > curr ? ans : curr);
	return 0;
}
