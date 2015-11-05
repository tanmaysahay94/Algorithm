#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long n;
		scanf("%lld", &n);
		if (n == 1)
		{
			printf("2\n");
			continue;
		}
		if ((n & (n + 1)) == 0)
			printf("%lld\n", n / 2);
		else
			printf("-1\n");
	}
	return 0;
}
