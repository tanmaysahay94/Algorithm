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
	int i, n;
	double x, y, curr, val;
	vector<double> angle;
	bool updated;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		updated = false;
		cin >> x >> y;
		angle.push_back(atan2(y, x) * 180/M_PI);
	}
	sort(angle.begin(), angle.end());
	// finding the largest angle WITHOUT the points
	val = angle[0] + 360 - angle[n - 1];
	for (i = 1; i < n; i++)
		val = max(val, angle[i] - angle[i - 1]);
	printf("%.6lf\n", 360 - val);
	return 0;
}
