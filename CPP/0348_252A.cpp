#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <functional>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long n, v, k, val, i, j, deal = 0;
	bool deal_made;
	vector<unsigned long long> ans;
	cin >> n >> v;
	for (i = 0; i < n; i++)
	{
		deal_made = false;
		cin >> k;
		for (j = 0; j < k; j++)
		{
			cin >> val;
			if (!deal_made && v > val)
			{
				deal_made = true;
				deal++;
				ans.push_back(i + 1);
			}
		}
	}
	cout << deal << endl;
	if (deal)
	{
		for (i = 0; i < ans.size() - 1; i++)
			cout << ans[i] << " ";
		cout << ans[i] << endl;
	}
	return 0;
}
