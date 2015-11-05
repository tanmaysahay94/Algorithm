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

int main()
{
    LL n, ans = 0;
    SLL(n);
	VLL v(n), u(n);
	for (int i = 0; i < n; i++)
		SLL(v[i]);
	for (int i = 0; i < n; i++)
	{
		u[i] = v[i];
		for (int j = 0; j < i; j++)
		{
			if (v[j] <= v[i])
				u[i] = max(u[i], u[j] + v[i]);
		}
		ans = max(ans, u[i]);
	}
	ans = -ans;
	for (int i = 0; i < n; i++)
		ans += v[i];
	printf("%lld\n", ans);
    return 0;
}
