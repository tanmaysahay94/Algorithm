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
	int n, i, j, max_weight;
	cin >> n;
	vector<pair<int, int> > item(n + 1);

	item[0] = make_pair(0, 0);
	for (i = 1; i <= n; i++)
		cin >> item[i].first >> item[i].second;		//first - weight, second - cost
	sort(item.begin(), item.end());

	cin >> max_weight;
	int profit[n + 1][max_weight + 1];

	for (i = 0; i <= n; i++)
		for (j = 0; j <= max_weight; j++)
			profit[i][j] = 0;

	for (i = 1; i <= n; i++)				// i - item index
	{
		for (j = 0; j <= max_weight; j++)	// j - knapsack weight limit
		{
			if (item[i].first > j)
				profit[i][j] = profit[i - 1][j];
			else
				profit[i][j] = max(profit[i - 1][j], profit[i - 1][j - item[i].first] + item[i].second);
		}
	}
	cout << profit[n][max_weight] << endl;
}
