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

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define SLL(n) scanf("%lld", &n)
#define SULL(n) scanf("%llu", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	LL t, x, y;
	SLL(t);
	while (t--)
	{
		bool paint = false;
		SLL(x); SLL(y);
		if (x > 0)
		{
			if (x & 1)
			{
				if ((y <= x + 1 and y >= 1 - x) or y % 2 == 0)
					paint = true;
			}
			else
			{
				if (y % 2 == 0)
					if (y >= x + 2 or y <= -x)
						paint = true;
			}
		}
		else
		{
			if (x % 2 == 0)
			{
				if ((y <= -x and y >= x) or y % 2 == 0)
					paint = true;
			}
			else
			{
				if (y % 2 == 0)
					if (y >= 1 - x or y <= x - 1)
						paint = true;
			}
		}
		if (paint)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
