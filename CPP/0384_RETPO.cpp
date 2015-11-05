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

typedef long long LL;

int main()
{
	LL t, x, y, ans, diff;
	cin >> t;
	while (t--)
	{
		cin >> x >> y;
		x = x > 0 ? x : -x;
		y = y > 0 ? y : -y;
		if (x == y)
			ans = 2 * x;
		if (x < y)
		{
			ans = 2 * x;
			y -= x;
			x = 0;
			if (y & 1)
				ans += (2 * y - 1);
			else
				ans += 2 * y;
		}
		else
		{
			ans = 2 * y;
			x -= y;
			y = 0;
			if (x & 1)
				ans += (2 * x + 1);
			else
				ans += 2 * x;
		}
		cout << ans << endl;
	}
	return 0;
}
