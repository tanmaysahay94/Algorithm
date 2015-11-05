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
	LL n, i, j, k, ans = 0;
	SLL(n);
	getchar();
	char g[2010][2010];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%c", &g[i][j]);
		getchar();
	}
	for (i = 0; i < n; i++)
	{
		VI fr, nfr;
		for (j = 0; j < n; j++)
			if (i != j)
				if (g[i][j] == '1')
					fr.pb(j);
				else
					nfr.pb(j);
		for (j = 0; j < nfr.size(); j++)
			for (k = 0; k < fr.size(); k++)
				if (g[fr[k]][nfr[j]]=='1')
				{
					ans++;
					break;
				}
	}
	printf("%lld\n", ans);
	return 0;
}
