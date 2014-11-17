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
	LL n, x, y, maxx = INT_MIN, maxy = INT_MIN, minx = INT_MAX, miny = INT_MAX;
	SLL(n);
	while (n--)
	{
		SLL(x); SLL(y);
		maxx = max(maxx, x);
		minx = min(minx, x);
		maxy = max(maxy, y);
		miny = min(miny, y);
	}
	LL side = max(abs(maxx - minx), abs(maxy - miny));
	printf("%lld\n", side * side);
	return 0;
}
