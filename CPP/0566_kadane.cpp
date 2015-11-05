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
		VLL v(n), u(n);
		for (int i = 0; i < n; i++)
		{
			sll(v[i]);
			u[i] = v[i];
		}
		sort(u.rbegin(), u.rend());
		LL noncon = 0, con = 0;
		for (int i = 0; i < n and u[i] >= 0; i++)
			noncon += u[i];
		if (!noncon and !u[0])
				noncon = u[0];
		if (u[0] <= 0)
			con = u[0];
		else
		{
			LL dp = v[0];
			con = v[0];
			for (int i = 1; i < n; i++)
			{
				dp = max(v[i], dp + v[i]);
				con = max(con, dp);
			}
		}
		printf("%lld %lld\n", con, noncon);
	}
	return 0;
}
