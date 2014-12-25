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
	int ax, ay, bx, by, cx, cy, dx, dy;
	cin >> ax >> ay >> bx >> by;
	if (ax == bx)
	{
		cx = ax + abs(by - ay);
		cy = ay;
		dx = cx;
		dy = by;
	}
	else if (ay == by)
	{
		cx = ax;
		cy = ay + abs(bx - ax);
		dx = bx;
		dy = cy;
	}
	else if (abs(ax - bx) == abs(ay - by))
	{
		cx = ax;
		cy = by;
		dx = bx;
		dy = ay;
	}
	else
	{
		cout << -1 << endl;
		return 0;
	}
	cout << cx << " " << cy << " " << dx << " " << dy << endl;
	return 0;
}
