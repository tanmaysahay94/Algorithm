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
	LL t, x, y, x1, y1, x2, y2, ans;
	SLL(t);
	while (t--)
	{
		SLL(x); SLL(y); SLL(x1); SLL(y1); SLL(x2); SLL(y2);
		ans = min(min(abs(x - x1), abs(x - x2)), min(abs(y - y1), abs(y - y2)));
		printf("%lld\n", ans);
	}
	return 0;
}
