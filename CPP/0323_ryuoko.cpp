#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <string.h>

using namespace std;

long long min(long long a, long long b)
{
	return a < b ? a : b;
}
int main()
{
	long long i, j, n, m, p, curr = 0;
	cin >> n >> m;
	vector<long long> v(m);
	vector<long long> neighbour[100110];
	for (i = 0; i < m; ++i)
		cin >> v[i];
	for (i = 0; i < m - 1; ++i)
		curr += abs(v[i] - v[i + 1]);
	p = curr;
	for (i = 0; i < m; i++)
	{
		if (i >= 1 && v[i - 1] != v[i])
			neighbour[v[i]].push_back(v[i - 1]);
		if (i + 1 < m && v[i] != v[i + 1])
			neighbour[v[i]].push_back(v[i + 1]);
	}
	for (i = 1; i <= n; i++)
	{
		long long sz = neighbour[i].size();
		if (sz)
		{
			sort(neighbour[i].begin(), neighbour[i].end());
			long long change = 0, median = neighbour[i][sz >> 1];
			for (j = 0; j < sz; j++)
				change += abs(neighbour[i][j] - median) - abs(neighbour[i][j] - i);
			curr = min(curr, p + change);
		}
	}
	cout << curr << endl;
}
