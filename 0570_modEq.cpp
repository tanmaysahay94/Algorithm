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
	LL a, b;
	cin >> a >> b;
	if (b > a)
		cout << 0;
	else if (a == b)
		cout << "infinity";
	else
	{
		LL ans = 0;
		a -= b;
		LL i;
		for (i = 1; i * i < a; i++)
		{
			if (i > b and a % i == 0)
				ans++;
			if (a/i > b and a % (a/i) == 0)
				ans++;
		}
		if (a == i * i and i > b)
			ans++;
		cout << ans;
	}
	cout << endl;
	return 0;
}
