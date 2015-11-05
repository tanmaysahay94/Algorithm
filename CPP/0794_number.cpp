#include <bits/stdc++.h>

using namespace std;

long long sieve[5000001], ans[5000001], val[5000001];

void preprocess()
{
	for (long long i = 0; i < 5000001; i++)
		val[i] = i, sieve[i] = 1;
	ans[1] = 0;
	sieve[0] = sieve[1] = 0;
	for (long long i = 2; i < 5000001; i++)
	{
		if (sieve[i])
		{
			ans[i]++;
			for (long long j = 2 * i; j < 5000001; j += i)
			{
				sieve[j] = 0;
				while (val[j] % i == 0)
				{
					val[j] /= i;
					ans[j]++;
				}
			}
		}
	}
	for (long long i = 2; i < 5000001; i++)
		ans[i] += ans[i - 1];
}

int main()
{
	preprocess();
	int t;
	scanf("%d", &t);
	while (t--)
	{
		long long a, b;
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", ans[a] - ans[b]);
	}
	return 0;
}
