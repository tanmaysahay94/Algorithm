#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#define _USE_MATH_DEFINES
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
typedef vector<int> VI;

#define SI(n) scanf("%d", &n)
#define sortv(v) sort(v.begin(), v.end())

typedef struct maxSum
{
	int sum, start, end;
} maxSum;

maxSum maxContiguousSubarray(vector<int>& v)
{
	maxSum ret;
	ret.sum = -2147483648;
	ret.start = ret.end = 0;
	int currSum = 0, currStart = 0, currEnd = 0;
	for (currEnd = 0; currEnd < v.size(); currEnd++)
	{
		currSum += v[currEnd];
		if (currSum > ret.sum)
		{
			ret.sum = currSum;
			ret.start = currStart;
			ret.end = currEnd;
		}
		if (currSum < 0)
		{
			currSum = 0;
			currStart = currEnd + 1;
		}
	}
	return ret;
}

int main()
{
	int n, i;
	SI(n);
	VI v(n);
	for (i = 0; i < n; i++)
		SI(v[i]);
	maxSum ans = maxContiguousSubarray(v);
	return 0;
}
