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
	LL n, target;
	cin >> n >> target;
	VLL v(n + 1);
	v[n] = 0;
	for (int i = 1; i < n; i++)
		cin >> v[i];
	bool reached = false;
	LL idx = 1;
	while (idx <= target and idx <= n)
	{
		if (idx == target)
		{
			reached = true;
			break;
		}
		idx = idx + v[idx];
	}
	if (reached)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
