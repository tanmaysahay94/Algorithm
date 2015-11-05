#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long l, r;
		scanf("%lld%lld", &l, &r);
		int ans = 0;
		long long foo = 2;
		while (foo <= r)
		{
			long long bar = foo;
			while (bar <= r)
			{
				if (l <= bar and bar <= r)
					ans++;
				bar *= 3;
			}
			foo *= 2;
		}
		if (l <= 1 and 1 <= r)
			ans++;
		printf("%d\n", ans);
	}
	return 0;
}
