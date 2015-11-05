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
	LL j, i, t, n;
	SLL(t);
	for (i = 1; i <= t; i++)
	{
		SLL(n);
		VLL v(n);
		for (j = 0; j < n; j++)
			SLL(v[j]);
		sortv(v);
		printf("Case %lld: %lld\n", i, v[n - 1] + v[n - 2] + v[n - 3]);
	}
	return 0;
}
