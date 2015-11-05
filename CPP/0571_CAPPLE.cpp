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
	int t;
	si(t);
	while (t--)
	{
		int n;
		si(n);
		LL ans = 1;
		VLL v(n);
		for (int i = 0; i < n; i++)
			sll(v[i]);
		sortv(v);
		for (int i = 1; i < n; i++)
			if (v[i] != v[i - 1])
				ans++;
		printf("%lld\n", ans);
	}
	return 0;
}
