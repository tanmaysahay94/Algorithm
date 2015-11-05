#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e7;

vector<long long> sieve(maxn, 1), prcnt(maxn, 0), palin(maxn, 0);

bool is(long long i)
{
	long long cmp = i;
	long long j = 0;
	while (cmp)
	{
		j = 10 * j + cmp % 10;
		cmp /= 10;
	}
	return i == j;
}

void init()
{
	sieve[0] = sieve[1] = 0;
	prcnt[0] = prcnt[1] = 0;
	palin[0] = palin[1] = 1;
	for (long long i = 2; i < maxn; i++)
	{
		if (sieve[i])
		{
			prcnt[i] = prcnt[i - 1] + 1;
			for (long long j = i << 1; j < maxn; j += i)
				sieve[j] = 0;
		}
		else
			prcnt[i] = prcnt[i - 1];
		palin[i] = palin[i - 1] + is(i);
	}
}

long long solve(long long p, long long q)
{
	long long ans = -1;
	for (long long i = maxn - 1; i >= 0 and ans == -1; i--)
		if (q * prcnt[i] <= p * palin[i])
			ans = i;
	return ans;
}

int main()
{
	init();
	long long p, q;
	scanf("%lld%lld", &p, &q);
	cout << solve(p, q);
	return 0;
}
