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

int c(int ax, int ay, int bx, int by, int cx, int cy)
{
	int la = pow(by - cy, 2) + pow(bx - cx, 2);
	int lb = pow(ay - cy, 2) + pow(ax - cx, 2);
	int lc = pow(ay - by, 2) + pow(ax - bx, 2);
	if ((la == lb + lc or lb == la + lc or lc == la + lb) and la and lb and lc) return 1;
	return 0;
}

int main()
{
	int ax, ay, bx, by, cx, cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	if (c(ax, ay, bx, by, cx, cy)) 
	{
		cout << "RIGHT\n";
		return 0;
	}
	if (c(ax + 1, ay, bx, by, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax - 1, ay, bx, by, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay + 1, bx, by, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay - 1, bx, by, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx + 1, by, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx - 1, by, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx, by + 1, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx, by - 1, cx, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx, by, cx + 1, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx, by, cx - 1, cy))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx, by, cx, cy + 1))
	{
		cout << "ALMOST\n";
		return 0;
	}
	if (c(ax, ay, bx, by, cx, cy - 1))
	{
		cout << "ALMOST\n";
		return 0;
	}
	cout << "NEITHER\n";
	return 0;
}
