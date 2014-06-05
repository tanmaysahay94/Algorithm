#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool cmp(long long a, long long b)
{
	return a > b;
}

int main()
{
	long long n, m, i, lim, total = 0;
	cin >> n >> m;
	lim = min(m, n);
	cout << lim << endl;
	vector<long long> devu(n), bro(m);
	for (i = 0; i < n; i++)
		cin >> devu[i];
	for (i = 0; i < m; i++)
		cin >> bro[i];
	sort(devu.begin(), devu.end());
	sort(bro.begin(), bro.end(), cmp);
	for (i = 0; i < lim && devu[i] < bro[i]; i++)
		total += (bro[i] - devu[i]);
	cout << total << endl;
}
