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
	ULL T, n, m, i, idx;
	scanf("%llu", &T);
	while (T--)
	{
		scanf("%llu%llu", &n, &m);
		vector<ULL> p(n);
		vector<vector<ULL> > cycle;
		vector<bool> visited(n, false);
		for (i = 0; i < n; i++)
			scanf("%llu", p[i]);
		if (n <= 2 or m <= 2)
		{
			printf("No Solution\n");
			continue;
		}
		for (i = 0; i < n; i++)
			if (not visited[i])
			{
				vector<ULL> curr;
				curr.push_back(i);
				idx = p[i];
				while (idx != i)
				{
					curr.push_back(idx);
					idx = p[idx];
				}
				cycle.push_back(curr);
			}
		vector<ULL> s(cycle.length());
		ULL sum = cycle[0].length;
		s[0] = sum * m;
		for (i = 1; i < cycle.length(); i++)
		{
			sum += cycle[i].length();
			s[i] = sum * m;
		}
	}
	return 0;
}
