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
	LL n, m, q;
	SLL(n); SLL(m);
	LL mid = (n << 1);
	LL high = mid + n;
	LL low = n + 2;
	while (m--)
	{
		SLL(q);
		if (q < low or q > high)
			printf("0\n");
		else
		{
			if (q <= mid + 1)
				printf("%lld\n", q - n - 1);
			else
				printf("%lld\n", high + 1 - q);
		}
	}
	return 0;
}
