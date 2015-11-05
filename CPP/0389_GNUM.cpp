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

#define val first
#define loc second

ULL gcd(ULL a, ULL b)
{
	ULL r;
	while (b)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ULL t, n, i, j, value;
	scanf("%llu", &t);
	while (t--)
	{
		scanf("%llu", &n);
		vector<pair<ULL, ULL> > a, b;
		vector<vector<bool> > s1(n, vector<bool> (n, false));		// i refers to index in a and j refers to index in b
		vector<vector<bool> > s2(n, vector<bool> (n, false));		// i refers to index in b and j refers to index in a
		vector<vector<ULL> > hcf(n, vector<ULL> (n));
		for (i = 0; i < n; i++)
		{
			scanf("%llu", &value);
			a.push_back(make_pair(value, i));
		}
		for (i = 0; i < n; i++)
		{
			scanf("%llu", &value);
			b.push_back(make_pair(value, i));
		}
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				hcf[i][j] = gcd(a[i].val, b[j].val);
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		vector<ULL> a_lookup(n), b_lookup(n);
		for (i = 0; i < n; i++)
		{
			a_lookup[a[i].loc] = i;
			b_lookup[b[i].loc] = i;
		}
	}
	return 0;
}
