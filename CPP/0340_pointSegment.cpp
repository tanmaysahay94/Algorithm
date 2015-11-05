#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <algorithm>
#include <utility>
#include <cassert>
#include <ctime>

using namespace std;

int main()
{
	long long n, m, i, a, b;
	cin >> n >> m;
	vector<long long> p(n), copy(n);
	vector<long long> c(101);
	for (i = 0; i < n; i++)
	{
		cin >> p[i];
		copy[i] = p[i];
	}
	sort(p.begin(), p.end());
	for (i = 0; i < m; i++)
		cin >> a >> b;
	for (i = 0; i < n; i++)
		c[p[i]] = i % 2;
	for (i = 0; i < n - 1; i++)
		cout << c[copy[i]] << " ";
	cout << c[copy[i]] << endl;
}
