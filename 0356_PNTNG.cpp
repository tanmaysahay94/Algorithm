#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
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
	unsigned long long n, m, h, i, painted = 0, cost = 0, to_paint;
	cin >> n >> m >> h;
	vector<pair<unsigned long long, unsigned long long> > tc(h);
	for (i = 0; i < h; i++)
	{
		cin >> tc[i].second >> tc[i].first;				// second - max to paint, first - cost
		painted += tc[i].second;
	}
	to_paint = n * m;
	if (painted < to_paint)
		cout << "Impossible\n";
	else
	{
		painted = 0;
		sort(tc.begin(), tc.end());
		for(i = 0; i < h; i++)
		{
			if (painted < to_paint)
			{
				painted += tc[i].second;
				cost += tc[i].first * tc[i].second;
				if (painted > to_paint)
				{
					cost -= (painted - to_paint) * tc[i].first;
					break;
				}
			}
			else
				break;
		}
		cout << cost << endl;
	}
	return 0;
}
