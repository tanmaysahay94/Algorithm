#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <utility>
#include <functional>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int i, n, m, a, b, ans = 0;
	cin >> n >> m;
	int v[n];
	for (i = 0; i < n; i++)
		cin >> v[i];
	for (i = 0; i < m; i++)
	{
		cin >> a >> b;
		a--;
		b--;
		ans += min(v[a], v[b]);
	}
	cout << ans << endl;
}
