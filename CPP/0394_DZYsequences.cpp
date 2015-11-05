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

#define sd(n) scanf("%d", &n)

int main()
{
	int n, i;
	sd(n);
	vector<int> v(n), to(n, 1), from(n, 1);
	for (i = 0; i < n; i++)
		sd(v[i]);
	for (i = 1; i < n; i++)
		if (v[i] > v[i - 1])
			to[i] = to[i - 1] + 1;
	for (i = n - 2; i >= 0; i--)
		if (v[i] < v[i + 1])
			from[i] = from[i + 1] + 1;
	int ans = 1;
	if (n > 1)
		ans = max(from[1] + 1, to[n - 2] + 1);
	for (i = 1; i < n - 1; i++)						// i is the index where value is changed
	{
		if (v[i + 1] - v[i - 1] > 1)
			ans = max(ans, to[i - 1] + from[i + 1] + 1);
		else
		{
			ans = max(ans, to[i - 1] + 1);
			ans = max(ans, from[i + 1] + 1);
		}
	}
	printf("%d\n", ans);
	return 0;
}
