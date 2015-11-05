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
#define each(it, v) for(__typeof(v.begin()) it(v.begin()); it != v.end(); it++)
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n;
	si(n);
	VI v(n);
	vector<pair<int, int> > ans;
	for (int i = 0; i < n; i++)
		si(v[i]);
	for (int i = 0; i < n; i++)
	{
		int mn = v[i], idx;
		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < mn)
			{
				mn = v[j];
				idx = j;
			}
		}
		if (mn < v[i])
			ans.pb(mp(i, idx)), swap(v[i], v[idx]);
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i].f << " " << ans[i].s << endl;
	return 0;
}
