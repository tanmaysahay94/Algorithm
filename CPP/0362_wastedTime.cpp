#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
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
	int n;
	float k, a, b, c, d, total = 0;
	cin >> n >> k;
	cin >> a >> b;
	n--;
	while (n--)
	{
		cin >> c >> d;
		total += sqrt(pow(a - c, 2) + pow(b - d, 2));
		a = c; b = d;
	}
	printf("%.6lf\n", total * k / 50.0);
	return 0;
}
