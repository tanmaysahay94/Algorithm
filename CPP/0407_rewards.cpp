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
#define sortv(v) sort(v.begin(), v.end())
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
#define f first
#define s second

int f(int a, int lim)
{
	int total = a / lim;
	if (a % lim) total++;
	return total;
}

int main()
{
	int a1, a2, a3, b1, b2, b3, given, least;
	cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3 >> given;
	int cups = a1 + a2 + a3;
	int meds = b1 + b2 + b3;
	least = f(cups, 5) + f(meds, 10);
	if (given >= least) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}
