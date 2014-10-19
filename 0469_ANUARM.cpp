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
	LL t, n, m, i;
	SLL(t);
	while (t--)
	{
		SLL(n); SLL(m);
		VLL pos(m);
		for (i = 0; i < m; i++)
			SLL(pos[i]);
		sortv(pos);
		LL least = pos[0];
		LL most = pos[m - 1];
		for (i = 0; i < n; i++)
			printf("%lld ", max(abs(i - least), abs(i - most)));
		printf("\n");
	}
	return 0;
}
