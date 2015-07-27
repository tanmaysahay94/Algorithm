#include <bits/stdc++.h>

using namespace std;

void optimizeIO()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}

multiset<int> v[1001], w[1001];

int main()
{
	optimizeIO();
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v[y].insert(x);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		w[b].insert(a);
	}
	int uu(0), vv(0);
	for (int dia = 1; dia <= 1000; dia++)
	{
		int tmp = 0;
		for (auto color: v[dia])
			if (w[dia].count(color))
				tmp++, w[dia].erase(w[dia].find(color));
		int foo = v[dia].size();
		int bar = w[dia].size();
		uu += tmp, vv += tmp;
		foo -= tmp;
		uu += min(foo, bar);
	}
	cout << uu << ' ' << vv;
	return 0;
}
