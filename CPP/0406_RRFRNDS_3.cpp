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
	char graph[2010][2010];
	LL frnd[2010][35] = {0};
	LL n, i, j, k, ans = 0;
	SLL(n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", graph[i]);
		for (j = 0; graph[i][j]; j++)
			if (graph[i][j] - '0')
				frnd[i][j / 64] |= (1LL << (j % 64));
	}
	LL lim = n / 64;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
			if (graph[i][j] == '0')
				for (k = lim; k >= 0; k--)
					if (frnd[i][k] & frnd[j][k])
					{
						ans += 2;
						break;
					}
	printf("%lld\n", ans);
	return 0;
}
