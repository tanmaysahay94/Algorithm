#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

struct city {
	public:
		long long x, y, pop;
		city(long long a, long long b, long long c): x(a), y(b), pop(c) {}
};

struct cmp {
	bool operator() (const city& a, const city& b) {
		return (a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y);
	}
};

int main()
{
	optimizeIO();
	int n, p;
	cin >> n >> p;
	vector<city> v;
	for (int i = 0; i < n; i++)
	{
		long long a, b, c;
		cin >> a >> b >> c;
		v.push_back(city(a, b, c));
	}
	sort(v.begin(), v.end(), cmp());
	bool done = false;
	for (int i = 0; i < n; i++)
	{
		p += v[i].pop;
		if (p >= (int) 1e6)
		{
			printf("%.6lf\n", sqrt(v[i].x * v[i].x + v[i].y * v[i].y));
			done = true;
			break;
		}
	}
	if (not done)
		cout << -1 << endl;
	return 0;
}
