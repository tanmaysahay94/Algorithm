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
	int lx, ly, lz, bx, by, bz, a1, a2, a3, a4, a5, a6, ans = 0;
	cin >> lx >> ly >> lz >> bx >> by >> bz >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	if (lx < 0) ans += a5;
	else if (lx > bx) ans += a6;
	if (ly < 0) ans += a1;
	else if (ly > by) ans += a2;
	if (lz < 0) ans += a3;
	else if (lz > bz) ans += a4;
	cout << ans << endl;
}
