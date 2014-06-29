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
	char t[5];
	cin >> t;
	int h = (t[0] - 48) * 10 + (t[1] - 48);
	double mm = (t[3] - 48) * 10 + (t[4] - 48);
	double hh = h % 12;
	cout << 30 * hh + mm / 2 << " " << 6 * mm << endl;
}
