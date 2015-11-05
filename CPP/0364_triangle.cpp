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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((a + b > c and b + c > a and c + a > b) or (b + c > d and c + d > b and d + b > c) or (a + c > d and c + d > a and d + a > c) or (a + b > d and b + d > a and d + a > b))
		cout << "TRIANGLE";
	else
	if (a + b == c or b + c == a or c + a == b or b + c == d or c + d == b or d + b == c or a + c == d or c + d == a or d + a == c or a + b == d or b + d == a or d + a == b)
		cout << "SEGMENT";
	else
		cout << "IMPOSSIBLE";
	cout << endl;
	return 0;
}
