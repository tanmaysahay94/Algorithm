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
	int n, m, a, b, c, node[1010];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &node[i]);
	double ans = 0;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &a, &b, &c);
		ans = max(ans, 1.0 * (node[a] + node[b]) / c);
	}
	printf("%.15lf\n", ans);
	return 0;
}
