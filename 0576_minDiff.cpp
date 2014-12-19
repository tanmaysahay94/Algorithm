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
	VI v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = INT_MAX;
	for (int i = 1; i < n - 1; i++)
	{
		VI a;
		for (int j = 0; j < n; j++)
			if (i != j)
				a.pb(v[j]);
		int d = INT_MIN;
		for (int j = 0; j < a.size() - 1; j++)
			d = max(d, a[j+1] - a[j]);
		ans = min(ans, d);
	}
	cout << ans << endl;
	return 0;
}
