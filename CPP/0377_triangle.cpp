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

#define x first
#define y second

int diff(int ax, int ay, int bx, int by)
{
	if (ax == bx and ay == by) return 0;
	return 1;
}

int check(int ax, int ay, int bx, int by, int cx, int cy)
{
	int px = ax - cx;
	int py = ay - cy;
	int qx = cx - bx;
	int qy = cy - by;
	int dot = px * qx + py * qy;
/*	printf("ax: %d ay: %d\nbx: %d by: %d\ncx: %d cy: %d\ndot: %d\n", ax, ay, bx, by, cx, cy, dot);
	printf("ax: %d ay: %d bx: %d by: %d diff: %d\n", ax, ay, bx, by, diff(ax, ay, bx, by));
	printf("ax: %d ay: %d cx: %d cy: %d diff: %d\n", ax, ay, cx, cy, diff(ax, ay, cx, cy));
	printf("cx: %d cy: %d bx: %d by: %d diff: %d\n", cx, cy, bx, by, diff(cx, cy, bx, by));
*/	if (dot == 0 and diff(ax, ay, bx, by) and diff(ax, ay, cx, cy) and diff(bx, by, cx, cy)) return 1;
	return 0;
}

int main()
{
	vector<pair<int, int> > pt;
	int i, j, k, px, py;
	bool right = false, almost = false;
	for (i = 0; i < 3; i++)
	{
		cin >> px >> py;
		pt.push_back(make_pair(px, py));
	}
/*	for (i = 0; i < 3; i++)
		printf("%d: %d %d\n", i, pt[i].x, pt[i].y);
*/	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (i != j and j != k and k != i)
					if (check(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y))
					{
						right = true;
						break;
					}
			}
			if (right) break;
		}
		if (right)
		{
			cout << "RIGHT\n";
			return 0;
		}
	}
//	printf("________________\nCheck ALMOST\n_________________\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 3; k++)
			{
				if (i != j and j != k and k != i)
				{
//					cout << "_____________________________\n";
					if (check(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x + 1, pt[k].y) or check(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x - 1, pt[k].y) or check(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y + 1) or check(pt[i].x, pt[i].y, pt[j].x, pt[j].y, pt[k].x, pt[k].y - 1))
					{
						almost = true;
						break;
					}
				}
			}
			if (almost) break;
		}
		if (almost)
		{
			cout << "ALMOST\n";
			return 0;
		}
	}
	cout << "NEITHER\n";
	return 0;
}
