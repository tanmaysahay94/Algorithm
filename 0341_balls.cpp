#include <iostream>
#include <vector>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, x, p, col, curr, ans = 0, i, l, r, d;
	cin >> n >> x >> p;
	vector<int> v(n);
	for (i = 0; i < n; i++)
		cin >> v[i];
	for (i = 0; i < n - 1; i++)
		if (v[i] == v[i + 1] && v[i] == p)
		{
			col = p;
			l = i;
			r = i + 1;
			curr = 0;
			while (l >= 0 && r < n)
			{
				d = 0;
				while (l >= 0 && v[l] == col)
					d++, l--;
				while (r < n && v[r] == col)
					d++, r++;
				if (!curr || d > 2)
					curr += d;
				else
					break;
				if (l >= 0 && r < n && v[l] == v[r])
					col = v[l];
				else
					break;
			}
			ans = max(ans, curr);
		}
	cout << ans << endl;
}
