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

#define loc first
#define idx second

int main()
{
	LL n, k, p, i, x_val, a, b;
	scanf("%lld%lld%lld", &n, &k, &p);
	vector<pair<LL, LL> > frog;
	vector<LL> lookup(n), reachable(n);
	LL curr = n - 1;
	reachable[curr] = curr;
	for (i = 0; i < n; i++)
	{
		scanf("%lld", &x_val);
		frog.push_back(make_pair(x_val, i));
	}
	sort(frog.begin(), frog.end());
	lookup[frog[n - 1].idx] = n - 1;
	for (i = n - 2; i >= 0; i--)
	{
		lookup[frog[i].idx] = i;
		if (frog[i + 1].loc - frog[i].loc > k)
			curr = i;
		reachable[i] = curr;
	}
	for (i = 0; i < p; i++)
	{
		scanf("%lld%lld", &a, &b);
		a--; b--;
		LL start = lookup[a];
		LL end = lookup[b];
		if (start > end)
			swap(start, end);
		if (end <= reachable[start])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
