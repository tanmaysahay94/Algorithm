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

ULL gcd(ULL a, ULL b)
{
	if (not b) return a;
	return gcd (b, a%b);
}

int main()
{
	ULL t, n, k;
	SULL(t);
	while (t--)
	{
		SULL(n); SULL(k);
		if (k > n)
		{
			printf("0\n");
			continue;
		}
		ULL lim = min(k, n - k);
		ULL ans = 1;
		for (ULL i = 1; i <= lim; i++)
		{
			ULL hcf = gcd(ans, i);
			ans /= hcf;
			ans *= (n - i + 1)/(i / hcf);
		}
		printf("%llu\n", ans);
	}
	return 0;
}
