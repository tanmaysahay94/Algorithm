#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define sull(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	VI ans(50);
	for (int i = 1; i < 50; i++)
		ans[i] = i ^ ans[i - 1];
	int t;
	si(t);
	while (t--)
	{
		int n, a, b;
		si(n);
		for (int i = 0; i < n; i++)
			si(a), si(b);
		printf("%d\n", ans[n]);
	}
	return 0;
}
