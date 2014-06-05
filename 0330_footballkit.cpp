#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
#include <vector>
#include <map>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

int main()
{
	unsigned long long i, j, n;
	cin >> n;
	vector<unsigned long long> c(100010, 0);
	vector< pair<unsigned long long, unsigned long long> > v(n), u(n, make_pair(n - 1, 0));
	for (i = 0; i < n; i++)
	{
		cin >> v[i].first >> v[i].second;
		c[v[i].first]++;
	}
	for (i = 0; i < n; i++)
	{
		u[i].first += c[v[i].second];
		u[i].second = 2 * (n - 1) - u[i].first;
	}
	for (i = 0; i < n; i++)
		cout << u[i].first << " " << u[i].second << endl;
}
