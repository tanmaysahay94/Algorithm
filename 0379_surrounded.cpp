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
	double ax, ay, ar, bx, by, br, val;
	cin >> ax >> ay >> ar >> bx >> by >> br;
	double dab = pow(pow(ax - bx, 2) + pow(ay - by, 2), 0.5);
	if (ar < br) swap(ar, br);
	if (dab + br >= ar and dab <= ar + br) val = 0;
	else if (ar + br < dab) val = dab - ar - br;
	else val = ar - dab - br;
	printf("%.9lf\n", val/2);
}
