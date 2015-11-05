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

const ULL mod = 1e9 + 7;

int main()
{
	ULL t, n, m, k, i, j;
	scanf("%llu", &t);
	while (t--)
	{
		scanf("%llu%llu%llu", &n, &m, &k);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				printf("A");
			printf("\n");
		}
	}
	return 0;
}
