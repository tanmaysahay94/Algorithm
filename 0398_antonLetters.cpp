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

int main()
{
	char c;
	int count = 0;
	vector<bool> l(26, false);
	cin >> c;
	while(c != '}')
	{
		if (c >= 'a' and c <= 'z' and not l[c - 'a'])
		{
			l[c - 'a'] = true;
			count++;
		}
		cin >> c;
	}
	cout << count << endl;
	return 0;
}
