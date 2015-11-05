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
	LL n, val, last;
	cin >> n;
	VLL a, b;
	for (LL i = 0; i < n; i++)
	{
		cin >> val;
		if (val > 0)
			a.pb(val);
		else if (val < 0)
			b.pb(-val);
		if (i == n - 1)
			if (val > 0)
				last = 1;
			else
				last = -1;
	}
	LL sum1 = 0, sum2 = 0;
	for (LL i = 0; i < sz(a); i++)
		sum1 += a[i];
	for (LL i = 0; i < sz(b); i++)
		sum2 += b[i];
	if (sum1 > sum2)
	{
		cout << "first\n";
		return 0;
	}
	else if (sum2 > sum1)
	{
		cout << "second\n";
		return 0;
	}
	LL idx = min(sz(a), sz(b));
	for (LL i = 0; i < idx; i++)
	{
		if (a[i] > b[i])
		{
			cout << "first\n";
			return 0;
		}
		else if (a[i] < b[i])
		{
			cout << "second\n";
			return 0;
		}
	}
	if (sz(a) > sz(b))
	{
		cout << "first\n";
		return 0;
	}
	else if (sz(a) < sz(b))
	{
		cout << "second\n";
		return 0;
	}
	if (last == 1)
		cout << "first\n";
	else
		cout << "second\n";
	return 0;
}
