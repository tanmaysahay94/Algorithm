#include <iostream>
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
	long long ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	long long l = (cx - bx) * (by - ay), m = (bx - ax) * (cy - by);
	if (l == m) cout << "TOWARDS\n";
	else if (l > m) cout << "RIGHT\n";
	else cout << "LEFT\n";
}
