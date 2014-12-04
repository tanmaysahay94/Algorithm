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

LL func(LL val)
{
	LL ans = 0;
	while (val)
	{
		LL dig = val % 10;
		ans += val;
		if (val % 2 == 0)
			ans += val;
		val /= 10;
	}
	return ans % 10;
}

int main()
{
	LL n;
	SLL(n);
	while (n--)
	{
		LL ans = 0;
		LL start, end;
		SLL(start);
		SLL(end);
		while (start < end and start % 10)
		{
			ans += func(start);
			start++;
		}
		while (end > start and end % 10)
		{
			ans += func(end);
			end--;
		}
		ans += 45 * ((end - start)/10);
		ans += func(end);
		printf("%lld\n", ans);
	}
	return 0;
}
