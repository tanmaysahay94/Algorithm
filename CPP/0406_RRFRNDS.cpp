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
	LL n, i, j, k, count = 0;
	SLL(n);
	vector<vector<int> > g(n, vector<int> (n));
	vector<int> frnd_list[n];
	getchar();
	char c;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%c", &c);
			g[i][j] = c -'0';
			if (g[i][j])
			{
				frnd_list[i].pb(j);
				frnd_list[j].pb(i);
			}
		}
		getchar();
	}
	vector<vector<int> > m(n, vector<int> (n, 0));
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (i != j and not g[i][j] and not m[i][j])
				for (k = 0; k < frnd_list[j].size(); k++)
					if (g[i][frnd_list[j][k]])
					{
						m[i][j] = 1;
						count++;
						break;
					}
	printf("%lld\n", count);
	return 0;
}
