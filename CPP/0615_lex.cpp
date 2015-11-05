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
	vector<pair<string, string> > v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].f >> v[i].s;
	VI order(n);
	for (int i = 0; i < n; i++)
	{
		cin >> order[i];
		order[i]--;
	}
	bool possible = true;
	string a, b, cur = min(v[order[0]].f, v[order[0]].s);
	for (int i = 1; i < n and possible; i++)
	{
		a = min(v[order[i]].f, v[order[i]].s);
		b = max(v[order[i]].f, v[order[i]].s);
		if (cur < a) cur = a;
		else if (cur < b) cur = b;
		else possible = false;
	}
	if (possible) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
