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
	cin >> n;
	VI v(n), pre(n+1, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		pre[i+1] = v[i] + pre[i];
	}
	int q;
	cin >> q;
	while (q--)
	{
		int val;
		cin >> val;
		VI::iterator it = lower_bound(pre.begin(), pre.end(), val);
		cout << it - pre.begin() << endl;
	}
	return 0;
}
