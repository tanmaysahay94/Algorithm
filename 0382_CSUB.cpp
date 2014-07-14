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

ULL summation(ULL number)
{
	return number * (number + 1) >> 1;
}

int main()
{
	ULL t, n, i;
	cin >> t;
	while (t--)
	{
		ULL count = 0;
		string s;
		cin >> n;
		cin >> s;
		for (i = 0; i < n; i++)
			if (s[i] == '1')
				count++;
		cout << summation(count) << endl;
	}
	return 0;
}
