#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

VI sieve(10000001, 1);
VI primacity(10000001, 0);

void init()
{
	sieve[0] = sieve[1] = 0;
	for (LL i = 2; i < 10000001; i++)
		if (sieve[i] == 1)
		{
			primacity[i] = 1;
			for (LL j = 2*i; j < 10000001; j += i)
				sieve[j] = 0, primacity[j]++;
		}
}

int main()
{
	init();
	LL t;
	sll(t);
	for (int test = 1; test <= t; test++)
	{
		LL a, b, k, ans = 0;
		sll(a); sll(b); sll(k);
		for (LL i = a; i <= b; i++)
			if (primacity[i] == k)
				ans++;
		printf("Case #%d: %lld\n", test, ans);
	}
	return 0;
}
