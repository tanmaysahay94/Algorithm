#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

typedef struct point
{
	long long x, y;
	bool operator <(const point& p) const {return (x < p.x or (x == p.x and y < p.y));}
} point;

double dist(vector<point>& h, int i, int j)
{
	double xd = h[i].x - h[j].x;
	double yd = h[i].y - h[j].y;
	return sqrt(xd * xd + yd * yd);
}

long long ccw(const point& O, const point& A, const point& B)
{
	return (long long)(A.x - O.x) * (long long) (B.y - O.y) - (long long) (B.x - O.x) * (long long) (A.y - O.y);
}

vector<point> graham_scan(vector<point>& v)
{
	int n = v.size();
	int sz = 0;
	vector<point> h(n<<1);
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++)		// build lower hull (usual stuff)
	{
		while (sz >= 2 and ccw(h[sz - 2], h[sz - 1], v[i]) <= 0)
			sz--;
		h[sz++] = v[i];
	}
	for (int i = n - 2, t = sz + 1; i >= 0; i--) // build upper hull!
	{
		while (sz >= t and ccw(h[sz - 2], h[sz - 1], v[i]) <= 0)
			sz--;
		h[sz++] = v[i];
	}
	h.resize(sz);
	return h;
}

int main()
{
	optimizeIO();
	int n;
	cin >> n;
	vector<point> v(n);
	for (int i = 0; i < n; i++)
	{
		point p;
		cin >> p.x >> p.y;
		v[i] = p;
	}
	vector<point> hull = graham_scan(v);
	double ans = 0;
	for (int i = 1; i < (int) hull.size(); i++)
		ans += dist(hull, i - 1, i);
	ans += dist(hull, 0, hull.size() - 1);
	printf("%lld\n", (long long)ans);
	return 0;
}
