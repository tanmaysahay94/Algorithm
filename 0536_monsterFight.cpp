#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<LL> VLL;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define sz(v) v.size()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int hy, ay, dy, hm, am, dm, hc, ac, dc;
	cin >> hy >> ay >> dy >> hm >> am >> dm >> hc >> ac >> dc;
	int ans = 1e9;
	for (int j = 0; j <= 300; j++)
		for (int k = 0; k <= 300; k++)
		{
			int a = ay + j;
			int d = dy + k;
			int sy = max(0, a - dm);
			int sm = max(0, am - d);
			if (not sy)
				continue;
			int n = (hm - 1)/sy + 1;
			int i = max(0, n*sm + 1 - hy);
			ans = min(ans, hc*i + ac*j + dc*k);
		}
	cout << ans << endl;
	return 0;
}
