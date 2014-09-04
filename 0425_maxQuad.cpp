#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL n, i, j, k, l, x, y, a1, a2, ans = 0;
	cin >> n;
	vector<pair<LL, LL> > pts;
	for (i = 0; i < n; i++)
	{
		cin >> x >> y;
		pts.pb(mp(x, y));
	}
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			a1 = a2 = -1;
			for (k = 0; k < n; k++)
			{
				if (k != i and k != j)
				{
					int temp = (pts[j].f - pts[i].f) * (pts[k].s - pts[j].s) - (pts[j].s - pts[i].s) * (pts[k].f - pts[j].f);
					if (temp < 0)
					{
						if (a1 < -temp)
							a1 = -temp;
					}
					else if (temp > 0)
					{
						if (a2 < temp)
							a2 = temp;
					}
				}
			}
			if (a1 >= 0 and a2 >= 0)
				ans = max(ans, a1 + a2);
		}
	}
	printf("%.6lf\n", (double) ans/2);
	return 0;
}
