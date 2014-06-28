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
	int n, i;
	double ans = 0;
	cin >> n;
	vector<unsigned long long> r(n);
	for (i = 0; i < n; i++)
		cin >> r[i];
	sort(r.begin(), r.end());
	if (n & 1)
	{
		ans += pow(r[0], 2);
		for (i = 1; i < n; i += 2)
			ans += pow(r[i + 1], 2) - pow(r[i], 2);
	}
	else
		for (i = 0; i < n; i += 2)
			ans += pow(r[i + 1], 2) - pow(r[i], 2);
	cout << ans * M_PI << endl;
	return 0;
}
