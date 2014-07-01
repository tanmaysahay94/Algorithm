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

double f(double slope)
{
	return atan(slope) * 180/M_PI;
}

int main()
{
	int i, n;
	double x, y, curr, val;
	vector<double> angle;
	bool updated;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		updated = false;
		cin >> x >> y;
		if (not x)
		{
			updated = true;
			if (y > 0) curr = 90;
			else curr = 270;
		}
		if (not updated and not y)
		{
			updated = true;
			if (x > 0) curr = 0;
			else curr = 180;
		}
		if (not updated)
		{
			updated = true;
			if (x > 0)
				if (y > 0) curr = f(y/x);
				else curr = 360 - f(-y/x);
			else
				if (y > 0) curr = 180 - f(-y/x);
				else curr = 180 + f(y/x);
		}
		// my own atan2 is from line 41 to 63
		if (curr >= 0 and curr <= 180) angle.push_back(curr);
		else angle.push_back(curr - 360);
	}
	sort(angle.begin(), angle.end());
	val = angle[0] + 360 - angle[n - 1];
	for (i = 1; i < n; i++)
		val = max(val, angle[i] - angle[i - 1]);
	printf("%.6lf\n", 360 - val);
	return 0;
}
