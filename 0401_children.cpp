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

typedef unsigned long long ULL;
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int main()
{
	int n, m, i;
	SI(n); SI(m);
	int candy, idx, ans = 0;
	for (i = 1; i <= n; i++)
	{
		SI(candy);
		candy = (candy - 1)/m;
		if (candy >= ans)
		{
			ans = candy;
			idx = i;
		}
	}
	printf("%d\n", idx);
	return 0;
}
