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

int main()
{
	LL t;
	sll(t);
	while (t--)
	{
		LL n, val, cnt = 0, sum = 0;
		sll(n);
		for (LL i = 0; i < n; i++)
		{
			sll(val);
			sum += val;
			if (val)
				cnt++;
		}
		if (sum >= 100 and sum <= 100 + cnt - 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
