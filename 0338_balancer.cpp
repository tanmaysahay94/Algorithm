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

using namespace std;

int main()
{
	long long n, i, sum = 0, moves = 0, val = 0;
	cin >> n;
	vector<long long> v(n);
	for (i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	sum /= n;
	for (i = 0; i < n; i++)
	{
		val += v[i] - sum;
		moves += abs(val);
	}
	cout << moves;
}
