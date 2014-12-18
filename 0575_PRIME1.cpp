#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL inf = 1e10;
LL lim = sqrt(inf);

VI basicSieve(lim + 1, 1);
VI primes;

void init()
{
	basicSieve[0] = basicSieve[1] = 0;
	for (int i = 2; i <= lim; i++)
	{
		if (!basicSieve[i]) continue;
		primes.pb(i);
		for (int j = i<<1; j <= lim; j += i)
			basicSieve[j] = 0;
	}
}

int main()
{
	init();
	LL t, n, m;
	sll(t);
	VI currPrime;
	while (t--)
	{
		sll(m); sll(n);
		if (m < 2)
			m = 2;
		LL size = n - m + 1;
		currPrime.resize(0);
		currPrime.resize(size);
		for (int i = 0; i < size; i++)
			currPrime[i] = 1;
		LL tlim = sqrt(n);
		int primesize = primes.size();
		for (int i = 0; i < primesize and primes[i] <= tlim; i++)
		{
			int prime = primes[i];
			LL val = m/prime;
			val *= prime;
			if (val == 0 or (val < lim and basicSieve[val]))
				val = prime<<1;
			for (LL j = val; j <= n; j += prime)
			{
				if (j < m) continue;
				currPrime[j - m] = 0;
			}
		}
		for (int i = 0; i < size; i++)
			if (currPrime[i])
				printf("%lld\n", i+m);
		printf("\n");
	}
	return 0;
}
