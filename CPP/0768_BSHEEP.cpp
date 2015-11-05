#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct point
{
	int x, y, idx;
	bool operator <(const point& p) const
	{
		if (y != p.y) return y < p.y;
		if (x != p.x) return x < p.x;
		return idx < p.idx;
	}
};

point p[100001], h[200002];

int ccw(point& o, point& a, point& b)
{
	return (a.x - o.x) * (b.y - o.y) - (b.x - o.x) * (a.y - o.y);
}

int main()
{
	optimizeIO();
	int t, n;
	scanf("%d", &t);
	for (int T = 0; T < t; T++)
	{
		if (T)
			printf("\n");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &p[i].x, &p[i].y);
			p[i].idx = i + 1;
		}
		sort(p, p + n);
		int sz = 1;
		for (int i = 1; i < n; i++)
		{
			if (p[i].x != p[i - 1].x || p[i].y != p[i - 1].y)
			{
				if (sz != i)
					p[sz] = p[i];
				sz++;
			}
		}
		n = sz;
		sz = 0;
		for (int i = 0; i < n; i++)
		{
			while (sz >= 2 and ccw(h[sz - 2], h[sz - 1], p[i]) <= 0)
				sz--;
			h[sz++] = p[i];
		}
		for (int i = n - 2, t = sz + 1; i >= 0; i--)
		{
			while (sz >= t and ccw(h[sz - 2], h[sz - 1], p[i]) <= 0)
				sz--;
			h[sz++] = p[i];
		}
		sz--;
		double ans = 0;
		for (int i = 0; i < sz; i++)
		{
			double xd = h[i].x - h[i + 1].x;
			double yd = h[i].y - h[i + 1].y;
			ans += sqrt(xd * xd + yd * yd);
		}
		printf("%.2lf\n", ans);
		for (int i = 0; i < sz; i++)
			printf(i == 0 ? "%d" : " %d", h[i].idx);
		printf("\n");
	}
	return 0;
}
