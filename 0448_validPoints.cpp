#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define PI(n) printf("%d", &n)
#define PLL(n) printf("%lld", &n)
#define PULL(n) printf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
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
	LL t, x1, y1, x2, y2;
	SLL(t);
	while (t--)
	{
		SLL(x1); SLL(y1); SLL(x2); SLL(y2);
		LL small = min(abs(x1 - x2), abs(y1 - y2));
		LL large = max(abs(x1 - x2), abs(y1 - y2));
		LL g = gcd(small, large);
		printf("%lld\n", g - 1);
	}
	return 0;
}
