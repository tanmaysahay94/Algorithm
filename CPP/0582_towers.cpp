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
	int n, k;
	si(n); si(k);
	vector<pair<int, int> > v(n);
	for (int i = 0; i < n; i++)
	{
		si(v[i].f);
		v[i].s = i + 1;
	}
	vector<pair<int, int> > ans;
	while (k--)
	{
		sortv(v);
		if (v[n-1].f == v[0].f)
			break;
		ans.pb(mp(v[n-1].s, v[0].s));
		v[n-1].f--; v[0].f++;
	}
	sortv(v);
	cout << v[n-1].f - v[0].f << " " << ans.size() << endl;
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i].f << " " << ans[i].s << endl;
	return 0;
}
