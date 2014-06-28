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
#define large 1000000007

int dig(int n)
{
	int v = 0;
	while (n /= 10) v++;
	return v + 1;
}

ULL window_sum(ULL a, ULL b)
{
	return (a - b + 1) * (a + b) >> 1;
}

int main()
{
	ULL t, leftdig, rightdig, total, l, r, temp;
	vector<ULL> min(10);
	min[0] = 1;
	for (int i = 1; i < 10; i++)
		min[i] = min[i - 1] * 10;
	cin >> t;
	while (t--)
	{
		cin >> l >> r;
		total = 0;
		leftdig = dig(l); rightdig = dig(r);
		if (leftdig == rightdig)
			total = leftdig * window_sum(r, l);
		else
		{
			total = leftdig * window_sum(r, l);
			for (int i = leftdig + 1; i <= rightdig; i++)
			{
				temp = window_sum(r, min[i - 1]);
				total = (total + temp) % large;
			}
		}
		cout << total % large << endl;
	}
}
