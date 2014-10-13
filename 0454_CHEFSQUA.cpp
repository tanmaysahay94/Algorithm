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
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define x first
#define y second

int main()
{
	LL n, ans = 2;
	SLL(n);
	vector<pair<double, double> > points(n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &points[i].x, &points[i].y);
	sortv(points);
	if (n <= 2)
		printf("%lld\n", 4 - n);
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				LL found = 2;
				double xc = (points[i].x + points[j].x)/2;
				double yc = (points[i].y + points[j].y)/2;
				double xd = (points[i].x - points[j].x)/2;
				double yd = (points[i].y - points[j].y)/2;
				double x3 = xc - yd;
				double y3 = yc + xd;
				double x4 = xc + yd;
				double y4 = yc - xd;
				if (binary_search(points.begin(), points.end(), mp(x3, y3)))
					found--;
				if (binary_search(points.begin(), points.end(), mp(x4, y4)))
					found--;
				ans = min(ans, found);
				if (ans == 0)
					break;
			}
			if (ans == 0)
				break;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
