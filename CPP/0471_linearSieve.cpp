#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

const LL size = 1e6 + 6;

VLL prime;
VLL firstPrime(size);

void linearSieve()
{
	for (LL i = 2; i < size; i++)
	{
		if (not firstPrime[i])
		{
			firstPrime[i] = i;
			prime.pb(i);
		}
		for (LL j = 0; j < prime.size() and prime[j] <= firstPrime[i] and prime[j] * i < size; j++)
			firstPrime[prime[j] * i] = prime[j];
	}
}

int main()
{
	linearSieve();
	for (LL i = 0; i < 100; i++)
		printf("%lld %lld\n", i, firstPrime[i]);
	return 0;
}
