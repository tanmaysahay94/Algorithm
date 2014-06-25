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
	vector<pair<int, int> > item(n);
	for (i = 0; i < n; i++)
		cin >> item[i].first >> item[i].second;		//first - weight, second - cost
	sort(item.begin(), item.end());
	cin >> max_weight;
	vector<int> weight(max_weight + 1, 0);			//index - weight, refers to a cost
	for (i = 1; i <= max_weight; i++)
		for (j = 0; item[j].first <= i; j++)
			weight[i] = max(weight[i], item[j].second + weight[i - item[j].first]);
	cout << weight[max_weight] << endl;
}
