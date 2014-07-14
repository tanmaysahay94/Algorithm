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

int main()
{
	char err[] = "No Solution";
	ULL T, n, m, i;
	scanf("%llu", &T);
	while (T--)
	{
		scanf("%llu%llu", &n, &m);
		vector<ULL> p(n);
		for (i = 0; i < n; i++)
			scanf("%llu", p[i]);
	}
	return 0;
}
