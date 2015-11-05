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
	LL val, n, curr = 0, ans = 0, maxVal = 0;
	SLL(n);
	for (int i = 0; i < n; i++)
	{
		SLL(val);
		ans += val;
		if (not val)
			curr++;
		else if (curr > 0)
			curr--;
		maxVal = max(maxVal, curr);
	}
	ans += maxVal;
	if (not maxVal)
		ans--;
	printf("%lld\n", ans);
	return 0;
}
