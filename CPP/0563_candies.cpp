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
	int n;
	cin >> n;
	VLL v(n), a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n; i++)
		a[i] = b[i] = 1;
	for (int i = 0; i < n - 1; i++)
		if (v[i] < v[i + 1])
			a[i + 1] = a[i] + 1;
	for (int i = n - 1; i > 0; i--)
		if (v[i - 1] > v[i])
			b[i - 1] = b[i] + 1;
	LL ans = 0;
	for (int i = 0; i < n; i++)
		ans += max(a[i], b[i]);
	cout << ans << endl;
	return 0;
}
