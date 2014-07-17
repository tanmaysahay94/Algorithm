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

#define SI(n) scanf("%d", &n)
#define Sint(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())

int main()
{
	int n, m, i, ans = 1500;
	SI(n); SI(m);
	vector<int> p(m);
	for (i = 0; i < m; i++)
		SI(p[i]);
	sortv(p);
	for (i = 0; i <= m - n; i++)
		ans = min(ans, p[i + n - 1] - p[i]);
	printf("%d\n", ans);
	return 0;
}
