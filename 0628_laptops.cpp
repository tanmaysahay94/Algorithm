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
	bool exist = false;
	int n;
	cin >> n;
	vector<PII> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].f >> v[i].s;
	sortv(v);
	for (int i = 1; i < n and not exist; i++)
		if (v[i].s < v[i - 1].s)
			exist = true;
	if (exist)
		cout << "Happy Alex" << endl;
	else
		cout << "Poor Alex" << endl;
	return 0;
}
