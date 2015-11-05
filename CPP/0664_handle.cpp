#include <bits/stdc++.h>

using namespace std;

typedef long long 				LL;
typedef unsigned long long 		ULL;
typedef vector<int> 			VI;
typedef vector<LL> 				VLL;
typedef pair<int, int> 			PII;
typedef pair<LL, LL> 			PLL;

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
	string a, b;
	vector<pair<string, string> > v;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		bool found = false;
		for (int j = 0; j < (int) v.size() and not found; j++)
			if (v[j].s == a)
				found = true, v[j].s = b;
		if (not found)
			v.pb(mp(a, b));
	}
	cout << v.size() << endl;
	for (int i = 0; i < (int) v.size(); i++)
		cout << v[i].f << ' ' << v[i].s << endl;
	return 0;
}
