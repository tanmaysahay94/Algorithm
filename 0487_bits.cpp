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

int main()
{
	ULL n, l, r;
	SULL(n);
	while (n--)
	{
		SULL(l); SULL(r);
		ULL ans = l;
		ULL bit = 0;
		while ((ans | (1ULL << bit)) <= r and bit < 64)
		{
			ans |= (1ULL << bit);
			bit++;
		}
		printf("%llu\n", ans);
	}
	return 0;
}
