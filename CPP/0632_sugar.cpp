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
	int n, dollar, a, b, out = 0;
	cin >> n >> dollar;
	bool ans = false;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (100 * a + b <= 100 * dollar)
		{
			ans = true;
			out = max(out, (100 - b) % 100);
		}
	}
	if (not ans)
		out = -1;
	cout << out << endl;
	return 0;
}
