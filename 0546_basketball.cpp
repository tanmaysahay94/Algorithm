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
	LL n, m;
	cin >> n;
	VLL a(n);
	for (LL i = 0; i < n; i++)
		cin >> a[i];
	sortv(a);
	cin >> m;
	VLL b(m);
	for (LL i = 0; i < m; i++)
		cin >> b[i];
	sortv(b);
	LL j = 0;
	LL p = 3 * n, q = 3 * m;
	LL ans = q, diff = p - q;
	for (LL i = 0; i < m; i++)
	{
		q--;
		while (j < n and a[j] <= b[i])
			p--, j++;
		if (p - q > diff)
		{
			diff = p - q;
			ans = q;
		}
	}
	cout << ans+diff << ":" << ans << endl;
	return 0;
}
