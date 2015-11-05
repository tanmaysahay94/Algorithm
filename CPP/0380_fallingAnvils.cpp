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
	double a, b;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		if (not b)
			cout << "1.000000\n";
		else if (not a)
			cout << "0.500000\n";
		else if (a <= 4 * b)
			printf("%.6lf\n", 0.5 + a / (16 * b));
		else
			printf("%.6lf\n", 1 - b/a);
	}
	return 0;
}
