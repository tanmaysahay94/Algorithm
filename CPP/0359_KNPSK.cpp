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

typedef unsigned long long ULL;

int main()
{
	ULL i, p, q, n, a, b, val, profit, max_val = 0, cur = 0;
	cin >> n;
	vector<ULL> one, two, temp;

	for (i = 0; i < n; i++)
	{
		cin >> val >> profit;
		if (val & 1) one.push_back(profit);
		else two.push_back(profit);
		max_val += val;
	}
	
	if (one.empty())
	{
		sort(two.begin(), two.end());
		int s2 = two.size();
		for (i = 0; i < s2; i++)
		{
			cout << cur << " ";
			cur += two[s2 - i - 1];
			cout << cur << " ";
		}
		return 0;
	}
	sort(one.begin(), one.end());
	int s1 = one.size();
	temp = two;
	for (i = 1; i < s1; i++)
		if (i & 1)
			two.push_back(one[s1 - i] + one[s1 - i - 1]);
		else
			temp.push_back(one[s1 - i] + one[s1 - i - 1]);
	sort(two.begin(), two.end());
	sort(temp.begin(), temp.end());
	ULL ans1 = one[s1 - 1];
	ULL ans2 = 0ll;
	int s2 = two.size();
	int st = temp.size();
	cout << ans1 << " ";
	for (i = 2; i <= max_val; i++)
	{
		if (i & 1)
			ans1 += temp[st - i/2];
		else
			ans2 += two[s2 - i/2];
		cout << max(ans1, ans2) << " ";
	}
	return 0;
}
