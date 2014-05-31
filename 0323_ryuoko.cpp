#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <string.h>

using namespace std;

int main()
{
	long long i, n, m, out = 0;
	cin >> n >> m;
	vector<long long> v(m), d(m - 1);
	for (i = 0; i < m; ++i)
		cin >> v[i];
	for (i = 0; i < m - 1; ++i)
		d[i] = v[i] - v[i + 1];
}
