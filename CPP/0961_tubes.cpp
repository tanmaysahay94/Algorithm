#include <bits/stdc++.h>

using namespace std;

void move(int& r, int& c, int& dir, int m)
{
	c += dir;
	if (c > m)
	{
		c = m;
		r++;
		dir *= -1;
	}
	else if (c == 0)
	{
		c = 1;
		r++;
		dir *= -1;
	}
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	int r = 1, c = 1;
	int dir = 1;
	for (int i = 1; i < k; i++)
	{
		cout << 2 << ' ';
		cout << r << ' ' << c << ' ';
		move(r, c, dir, m);
		cout << r << ' ' << c << ' ';
		move(r, c, dir, m);
		cout << endl;
	}
	cout << n * m - 2 * (k - 1) << ' ';
	for (int i = 0; i < n * m - 2 * (k - 1); i++)
	{
		cout << r << ' ' << c << ' ';
		move(r, c, dir, m);
	}
	return 0;
}
