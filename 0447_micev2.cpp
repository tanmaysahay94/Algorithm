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

int main()
{
	LL t, n, m;
	while (t--)
	{
		VLL mice(n), holes(m);
		for (int i = 0; i < n; i++)
			SLL(mice[i]);
		for (int i = 0; i < m; i++)
			SLL(holes[i]);
		sortv(mice); sortv(holes);
	}
	return 0;
}
