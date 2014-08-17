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
#define pn puts("")

int main()
{
	int n, val;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		cin >> val;
		v.push_back(val);
	}
	int f;
	cin >> f;
	cout << *(find(v.begin(), v.end(), f)) << endl;
	return 0;
}
