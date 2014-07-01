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
int dot(int ax, int ay, int bx, int by, int cx, int cy)
{
	return (ax - bx) * (bx - cx) + (ay - by) * (by - cy);
}
int c(int ax, int ay, int bx, int by)
{
	if (ax == bx and ay == by)
		return 0;
	return 1;
}
int t(int ax, int ay, int bx, int by, int cx, int cy)
{
	if (c(ax, ay, bx, by) and c(ax, ay, cx, cy) and c(bx, by, cx, cy))
		return 1;
	return 0;
}
int main()
{
	int te;
	cin >> te;
	while (te--)
	{
		int ax, ay, bx, by, cx, cy;
		cin >> ax >> ay >> bx >> by >> cx >> cy;
		printf("dot: %d triangle: %d\n", dot(ax, ay, bx, by, cx, cy), t(ax, ay, bx, by, cx, cy));
	}
}
