#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <cassert>
#include <utility>
#include <bits/stdc++.h>
#include <stack>
#include <cstdlib>
#include <set>

using namespace std;

int main()
{
	int a, b, lim, i, j, val;
	vector< pair<int, int> > p, q;
	bool found = false;
	cin >> a >> b;
	int a2 = a * a;
	int b2 = b * b;
	int dx, dy;
	lim = max(a, b);
	for (i = -lim; i <= lim; i++)
		for (j = -lim; j <= lim; j++)
		{
			val = i * i + j * j;
			if (i and j)
			{
				if (val == a2) p.push_back(make_pair(i, j));
				if (val == b2) q.push_back(make_pair(i, j));
			}
		}
	for (i = 0; i < p.size(); i++)
	{
		for (j = 0; j < q.size(); j++)
		{
			dx = p[i].first * q[j].first; dy = p[i].second * q[j].second;
			if (not(dx + dy) and p[i].first - q[j].first and p[i].second - q[j].second)
			{
				found = true;
				break;
			}
		}
		if (found) break;
	}
	if (found) printf("YES\n0 0\n%d %d\n%d %d\n", p[i].first, p[i].second, q[j].first, q[j].second);
	else printf("NO\n");
	return 0;
}
