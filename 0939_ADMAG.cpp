#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long t;
	scanf("%lld", &t);
	while (t--)
	{
		long long n;
		scanf("%lld", &n);
		long long first = 1, ans = 1;
		long long second = first + 1;
		long long third = second + 1;
		if (n == 1 or n == 2)
		{
			printf("%lld\n", n);
			continue;
		}
		while (second <= n)
		{
			ans++;
			first = second;
			second = third;
			third = first + second;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
