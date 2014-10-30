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

int main()
{
	LL inf = 1e6 + 1;
	VI present(inf, 0), ans;
	LL n, num, pairs = 0;
	SLL(n);
	for (int i = 0; i < n; i++)
	{
		SLL(num);
		present[num] = 1;
		if (present[inf - num])
			pairs++;
	}
	printf("%lld\n", n);
	for (int i = 1; i <= inf; i++)
	{
		if ((not present[i] and not present[inf - i]) and pairs > 0)
		{
			ans.pb(i); ans.pb(inf - i);
			pairs--;
		}
		if (present[i] and not present[inf - i])
			ans.pb(inf - i);
	}
	for (int i = 0; i < ans.size(); i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
