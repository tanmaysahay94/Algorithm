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
	int T, n, k, i, val;
	SI(T);
	while (T--)
	{
		int even = 0;
		SI(n); SI(k);
		for (i = 0; i < n; i++)
		{
			SI(val);
			if (val % 2 == 0)
				even++;
		}
		if ((even == n and k == 0) or even < k)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
