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

int main()
{
	long long n, i, j, c, k, count = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
		for (j = i; j < n; j++)
		{
			c = i * i + j * j;
			k = sqrt(c);
			k *= k;
			if (c > n * n) break;
			if (k == c) count++;
		}
	cout << count << endl;
	return 0;
}
