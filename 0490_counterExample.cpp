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
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

LL gcd(LL a, LL b)
{
	if (not b) return a;
	return gcd(b, a % b);
}

int main()
{
	LL l, r, ans = 0;
	SLL(l); SLL(r);
	for (LL i = l; i <= r; i++)
	{
		for (LL j = l; j <= r; j++)
		{
			for (LL k = l; k <= r; k++)
				if (i < j and j < k and gcd(i, j) == 1 and gcd(j, k) == 1 and gcd(i, k) != 1)
				{
					printf("%lld %lld %lld\n", i, j, k);
					ans = 1;
					break;
				}
			if (ans) break;
		}
		if (ans) break;
	}
	if (not ans)
		printf("-1\n");
	return 0;
}
