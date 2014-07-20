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

void M(LL val, LL m)
{
	LL p = val % m;
	if (p and val < 0) cout << p + m;
	else cout << p;
	cout << endl;
}

int main()
{
	LL x, y, n, mod = 1e9 + 7;
	cin >> x >> y >> n;
	n = (n - 1) % 6;
	switch (n)
	{
		case 0: M(x, mod); break;
		case 1: M(y, mod); break;
		case 2: M(y - x, mod); break;
		case 3: M(-x, mod); break;
		case 4: M(-y, mod); break;
		case 5: M(x - y, mod); break;
	}
	return 0;
}
