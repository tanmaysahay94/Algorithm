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
	double vb, vs, ux, uy, curr, min = 1e14;
	int i, n, idx;
	cin >> n >> vb >> vs;
	vector<double> loc(n);
	for (i = 0; i < n; i++)
		cin >> loc[i];
	cin >> ux >> uy;
	for (i = 1; i < n; i++)
	{
		curr = loc[i]/vb + pow(pow(ux - loc[i], 2) + pow(uy, 2), 0.5)/vs;
		if (curr <= min)
		{
			min = curr;
			idx = i + 1;
		}
	}
	cout << idx << endl;
	return 0;
}
